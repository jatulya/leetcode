class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char x){
            return !isalnum(x);
        }), s.end());

        int len = s.size();
        bool pal = true;

        for (int i=0; i<len/2; i++){
            if (tolower(s[i]) != tolower(s[len-i-1])){
                pal = false;
                break;
            }
        }

        return pal;
    }
};
