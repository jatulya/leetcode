class Solution {
public:
    string longestPalindrome(string s) {
        int maxstart = 0, maxend=1;

        for (int i=0; i<s.size(); i++){
            middlePal(s, i, i, maxstart, maxend);
            middlePal(s, i, i+1, maxstart, maxend);
        }
        return s.substr(maxstart, maxend);
    }

private:
    void middlePal(string s, int i, int j, int& start, int& end){
        while (i>=0 && j<s.size() && s[i]==s[j]){
            i--; j++;
        }
        if ((j-i-1)>end){
            start = i+1;
            end = j-i-1;
        }
    }
};
