class Solution {
public:
    string minWindow(string s, string t) {
        int m= s.size();
        if (m<t.size()) return "";
        //finding the count of each character
        unordered_map<char,int> countT;
        for (char c: t)
            countT[c]+=1;
        
        int have=0, need=countT.size(), start=0, minlen = INT_MAX, l=0,r=0;
        while(r<m){
            if (countT[s[r]]){
                countT[s[r]]--;
                if (!countT[s[r]])
                    have++;
            }
            while (have==need){
                if (r-l+1 <minlen){
                    start=l;
                    minlen = r-l+1;
                }
                if (countT[s[l]]){
                    countT[s[l]]++;
                    if (countT[s[l]]) have--;
                } 
                l++;
            }
            r++;    
        }        

        return minlen == INT_MAX ? "" : s.substr(start,minlen);
    }
};
