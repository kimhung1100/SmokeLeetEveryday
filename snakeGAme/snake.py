import pygame, sys, time, random

speed = 15

#windows size

frame_size_x = 720
frame_size_y = 480

check_errors = pygame.init()
if check_errors[1] > 0:
    print("(!) Had {0} initializing errors, exiting...".format(check_errors[1]))
    sys.exit(-1)
else:
    print("(+) PyGame successfully initialized!")

pygame.display.set_caption("Snake Game")
game_window = pygame.display.set_mode((frame_size_x, frame_size_y))

# colors
black = pygame.color.THECOLORS['black']
white = pygame.color.THECOLORS['white']
red = pygame.color.THECOLORS['red']
green = pygame.color.THECOLORS['green']
blue = pygame.color.THECOLORS['blue']

fps_controller = pygame.time.Clock()

# one snake square size
square_size = 20

def init_var():
    global snake_pos, snake_body, snake_direction
    global food_pos, score, food_spawned
    snake_pos = [100, 50]
    snake_body = [[100, 50], [90, 50], [80, 50]]
    snake_direction = "RIGHT"
    food_pos = [random.randrange(1, (frame_size_x // square_size) - 1) * square_size,
                random.randrange(1, (frame_size_y // square_size) - 1) * square_size]
    score = 0
    food_spawned = true

init_var()

def show_score():
    score_font = pygame.font.SysFont('monaco', 15)
    score_surface = score_font.render('Score: {0}'.format(score), True, black)
    score_rect = score_surface.get_rect()
    score_rect.topleft = (frame_size_x - 120, 10)
    game_window.blit(score_surface, score_rect)
    if choice == 1:
        score_rect.midtop = (frame_size_x // 2, 10)
    else:
        score_rect.midtop = (frame_size_x // 2, frame_size_y - 20)
        game_window.blit(score_surface, score_rect)


    #game loop
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RIGHT or event.key == ord('d'):
                    snake_direction = "RIGHT"
                if event.key == pygame.K_LEFT or event.key == ord('a'):
                    snake_direction = "LEFT"
                if event.key == pygame.K_UP or event.key == ord('w'):
                    snake_direction = "UP"
                if event.key == pygame.K_DOWN or event.key == ord('s'):
                    snake_direction = "DOWN"
                if event.key == pygame.K_ESCAPE:
                    pygame.event.post(pygame.event.Event(pygame.QUIT))
        #snake movement
        if snake_direction == "RIGHT":
            snake_pos[0] += square_size
        elif snake_direction == "LEFT":
            snake_pos[0] -= square_size
        elif snake_direction == "UP":
            snake_pos[1] -= square_size
        elif snake_direction == "DOWN":
            snake_pos[1] += square_size
        
        if snake_pos[0] < 0:
            snake_pos[0] = frame_size_x - square_size
        elif snake_pos[0] > frame_size_x - square_size:
            snake_pos[0] = 0
        elif snake_pos[1] < 0:
            snake_pos[1] = frame_size_y - square_size
        elif snake_pos[1] > frame_size_y - square_size:
            snake_pos[1] = 0
        
        # eating apple
        snake_body.insert(0, list(snake_pos))
        if snake_pos[0] == food_pos[0] and snake_pos[1] == food_pos[1]:
            score += 1
            food_spawned = False
        else:
            snake_body.pop()

        # spawn food
        if food_spawned == False:
            food_pos = [random.randrange(1, (frame_size_x // square_size) - 1) * square_size,
                        random.randrange(1, (frame_size_y // square_size) - 1) * square_size]
            food_spawned = True

        # GFX
        game_window.fill(black)
        for pos in snake_body:
            pygame.draw.rect(game_window, green, pygame.Rect(
                pos[0] + 2, pos[1] + 2, square_size - 2, square_size))

        pygame.draw.rect(game_window, red, pygame.Rect(
            food_pos[0], food_pos[1], square_size, square_size))
        
        # game over condition
        for block in snake_body[1:]:
            if snake_pos[0] == block[0] and snake_pos[1] == block[1]:
                init_var()
            
        show_score()
        pygame.display.update()
        fps_controller.tick(speed)




