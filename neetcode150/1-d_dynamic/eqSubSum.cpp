class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //soln similar to 0/1 knapsack
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target%2) return false;
        
        target /= 2;
        vector<bool> dp(target+1, false);
        dp[0] = true; // possible to achieve 0 sum

        for(int i: nums){
            for(int j=target; j>=i; j--)
                dp[j] = dp[j] || dp[j-i];
            if (dp[target]) return true;
        }

        return false;

    }
};
