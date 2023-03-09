#case 2: rotate 1 .. n -1, min in the mid of list

#case 1: rotate n times, min in left of list

class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        left = 0
        right = n - 1
        mid = (n - 1)//2

        if(nums[right] > nums[left]):
            return nums[left]      # case 1
        # case 2: find the min in the mid of list
        while left < right:
            mid = (right + left) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        return nums[left]
            
