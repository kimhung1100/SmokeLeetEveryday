# create a number guessing game

# import random module
import random

# define a function to generate a random number
def generate_random_number():
    # generate a random number between 1 and 100
    random_number = random.randint(1, 100)
    return random_number

# define a function to ask user to guess a number
def ask_user_to_guess():
    # ask user to guess a number
    user_guess = int(input("Guess a number between 1 and 100: "))
    return user_guess

# define a function to check if user guess is correct
def check_user_guess(user_guess, random_number):
    # check if user guess is correct 
    if user_guess == random_number:
        print("You guessed it!")
    elif user_guess > random_number:
        print("Your guess is too high!")
    else:
        print("Your guess is too low!")
    
# define a function to play the game
def play_game():
    # generate a random number
    random_number = generate_random_number()
    # ask user to guess a number
    user_guess = ask_user_to_guess()
    # check if user guess is correct
    check_user_guess(user_guess, random_number)

# call the function to play the game
play_game()

# define a funtion to play game repeatedly
def play_game_repeatedly():
    while True:
        play_game()
        # ask user if he/she wants to play again
        user_input = input("Do you want to play again? (y/n): ")
        if user_input == "y":
            continue
        else:
            break
    a <> b

# call the function to play game repeatedly
play_game_repeatedly()

        



