class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        /* using dp
        vector<vector<long long>> dp (n+ 1, vector<long long> (2,0));
        for(int i=n-1; i>=0; i--){
            //for num in even pos, 
            //val = max of this num + next num in odd pos and next num in even pos
            dp[i][1] = max(nums[i]+dp[i+1][0], dp[i+1][1]);
            //for num in of pos, 
            //max of this negative of num + next num in even pos and next num in odd pos
            dp[i][0] = max(-nums[i]+dp[i+1][1], dp[i+1][0]);
        }
        return dp[0][1];
        */

        //space optimized
        long long sumEven = 0, sumOdd = 0;
        for(int i=n-1; i>=0; i--){
            sumEven = max(nums[i]+sumOdd, sumEven);
            sumOdd = max(-nums[i]+sumEven, sumOdd);
        }
        return sumEven;
    }
};
