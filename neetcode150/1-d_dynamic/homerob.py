class Solution:
    def rob(self, nums: List[int]) -> int:

        robcurr, robnext = 0, nums[-1]

        for n in nums[len(nums)-2::-1]:
            maxrobofcurr = max(n+robcurr, robnext)
            robcurr = robnext
            robnext = maxrobofcurr
        
        return robnext
        
''' Cpp solution where values are checked from starting of the array
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1)
            return nums[0];
        
        int prev2=0, curr=0, prev1=0;
        for (int n: nums){
            curr = max(prev2+n, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
}; '''
