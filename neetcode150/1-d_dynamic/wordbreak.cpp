class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //for efficient lookup
        unordered_set<string> words (wordDict.begin(), wordDict.end());
        int n = s.length();

        //dp[j] ==> if the word from 0 to j-1 can be broken into wordDict words.
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i=1; i<=n; i++)
            for(int j=i-1; j>=0; j--)
                if (dp[j] && words.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
        
        return dp[n];
    }
};
