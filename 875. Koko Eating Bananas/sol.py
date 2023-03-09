class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)
        ans = right

        while(left <= right):
            mid = (right + left) // 2
            totalTimes = 0
            for p in piles:
                totalTimes += ((p-1)//mid)+1
            if totalTimes <= h:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans 

