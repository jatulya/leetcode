class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int i=1; i<amount+1; i++)
            for(int j=0; j<coins.size(); j++){
                int val = i - coins[j];
                if (val >= 0)
                    dp[i] = min(dp[i], 1 + dp[val]);
            }
        
        if (dp[amount]==amount+1)
            return -1;
        
        return dp[amount];
    }  
};
/*
  here, the tree is drawn with amount remaining after the current coin value is reduced.
  ==> repeating subproblems are amount remaining. thus, 0 - amount indices are taken as the dp array.
*/
