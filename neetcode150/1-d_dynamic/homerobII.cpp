class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        
        if (n==1)
            return nums[0];
        if (n==2)
            return max(nums[0], nums[1]);
        return max(rob1(nums, 0, n-1), rob1(nums, 1, n));
    }
private:
    int rob1(vector<int>& nums, int start, int end){
        int prev1 = 0; // max robbery till just before home
        int curr=0; //max robbery at current house
        int prev2 = 0; //max robbery at two houses before

        for (int i=start; i<end; i++){
            curr = max(prev2+nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};
