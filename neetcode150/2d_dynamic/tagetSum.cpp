/*class Solution { 
    //int totalSum = 0;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
       // totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<unordered_map<int,int>> dp(nums.size()+1);
        return backtrack(0, target, nums, dp);
    }

private:
    int backtrack(int i, int total, vector<int>& nums, vector<unordered_map<int,int>>& dp){
        if (i==nums.size())
            return total==0;
        
        if (dp[i].count(total))
            return dp[i][total];
        
        dp[i][total] = backtrack(i+1, total - nums[i], nums, dp ) + backtrack(i+1, total + nums[i], nums, dp );

        return dp[i][total];
    }
};*/
// faster soln
class Solution {
    vector<vector<int>> dp;
    int totalSum;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));
        return backtrack(0, 0, nums, target);
    }
    
    int backtrack(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target;
        }
        if (dp[i][total + totalSum] != INT_MIN) {
            return dp[i][total + totalSum];
        }
        dp[i][total + totalSum] = backtrack(i + 1, total + nums[i], nums, target) + 
                                  backtrack(i + 1, total - nums[i], nums, target);
        return dp[i][total + totalSum];
    }
};
