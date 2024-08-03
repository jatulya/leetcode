class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 =s2.length();
        
        if (l1>l2) return false;
        
        unordered_map<char, int> map1, map2;
        for (char c: s1) map1[c]++;   
        
        int l=0, r=0, match=0;
        while (r<l2){
            if (map1.find(s2[r])!=map1.end()){
                map2[s2[r]]++;
                if (map2[s2[r]]==map1[s2[r]]) match++;
            }

            if (r-l+1 == l1){
                if (match==map1.size()) return true;

                if (map2.find(s2[l])!=map1.end()){
                    if (map2[s2[l]]==map1[s2[l]]) match--;
                    map2[s2[l]]--;
                }
                l++;
            }   
            
            r++;
        }

        return false;
    }
};
