class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        top, bot = 0, len(matrix) -1
        left, right = 0, len(matrix[0]) -1
        while top <= bot:   
            row = top + (bot - top) // 2
            if target > matrix[row][-1]:
                top = row + 1
            elif target < matrix[row][0]:
                bot = row - 1
            else:
                break

        if not(top <=bot):
            return False
            
        while left <= right:
            mid = left + (right - left) // 2
            if target > matrix[row][mid]:
                left = mid + 1
            elif target < matrix[row][mid]:
                right = mid - 1
            else:
                return True
        return False
