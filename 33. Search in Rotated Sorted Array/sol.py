# There is an integer array nums sorted in ascending order (with distinct values).

# Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

# Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

# You must write an algorithm with O(log n) runtime complexity.

# the list is 2 part
# step 1: find target in which part
# step 2: bin search on that part
class Solution:
    def search(self, nums: list[int], target: int) -> int:
        ans = -1
        l, r = 0, len(nums) - 1
        if(target == nums[r]): return r
        if(len(nums) == 2):
            if(target == nums[0]): return 0
            else: return -1;
        

        while(l <= r):
            
            mid = (r + l) // 2
            if(target == nums[mid]): return mid
            
            # mid in left part
            if(nums[l] <= nums[mid]):
                if(target > nums[mid] or target < nums[l]):
                    l = mid + 1
                else:
                    r = mid - 1
                    
            
            # mid in right part
            else:
                if(target < nums[mid] or target > nums[r]):
                    r = mid - 1
                else:
                    l = mid + 1
        return ans
def test_search():
    s = Solution()
    print(s.search([4,5,6,7,0,1,2], 0))

test_search()