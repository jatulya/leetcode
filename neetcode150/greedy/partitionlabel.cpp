class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.length()==1)
            return {1};

        vector<int>lastindex(26,-1), result;
        int currend = 0, partitionstart = 0;

        for (int i=0; i<s.length();i++)
            lastindex[s[i]-'a'] =i;
        
        for (int i=0; i<s.length();i++){
            currend = max(currend, lastindex[s[i]-'a']);
            if (i==currend){
                result.push_back(currend-partitionstart+1);
                partitionstart = currend+1;
            }
        }

        return result;
    }
};
