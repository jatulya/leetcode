class Solution {
public:
    bool isAnagram(string s, string t) {

        if  (s.size() != t.size()){
            return false;
        }

        unordered_map <char, int> lettersOfS;
        for (char ch: s ){
             lettersOfS[ch]++;
        }

        for (char ch: t ){
            lettersOfS[ch]--;
        }

        for(auto& key: lettersOfS){
            if (key.second != 0){
                return false;
            }
        }

        return true;
    }
};
