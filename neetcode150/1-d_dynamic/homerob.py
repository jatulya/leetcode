class Solution:
    def rob(self, nums: List[int]) -> int:

        robcurr, robnext = 0, nums[-1]

        for n in nums[len(nums)-2::-1]:
            maxrobofcurr = max(n+robcurr, robnext)
            robcurr = robnext
            robnext = maxrobofcurr
        
        return robnext
        
