// recursion with dp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int n : nums)
            sum += n;
        
        if (sum%2) return false;
        
        vector<vector<int>> dp (nums.size(), vector<int> ((sum/2)+1, -1));
        return dfs(nums, 0, sum/2, dp);        
    }

private:
    bool dfs(vector<int>& nums, int i, int sum, vector<vector<int>>& dp){
        if (!sum) return true;

        if (i >= nums.size() || sum <0) return false;

        if (dp[i][sum]==-1) 
            dp[i][sum] = (dfs(nums, i+1, sum-nums[i], dp) 
                    || dfs(nums, i+1, sum, dp));
        return dp[i][sum];    
    }
};

//dp without recursion - space optimised
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

