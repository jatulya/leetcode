class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0]=='0')
            return 0;
        
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=s.length(); i++){
            int onedigit = stoi(s.substr(i-1, 1));
            int twodigit = stoi(s.substr(i-2, 2));
            
            if (onedigit)
                dp[i]+=dp[i-1];c
            if (twodigit>=10 && twodigit<=26)
                dp[i]+=dp[i-2];
        }

        return dp[s.length()];

    }
};
