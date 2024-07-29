#include<sstream>

class Solution {
public:

    string encode(vector<string>& strs) {
        string newstr = "";
        for(const string& s: strs){
            newstr += to_string(s.size()) + "#" + s;
        }
        return newstr;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;

        while (i<s.size()){
            int j=i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        return result;
    }
};
// header files - iostream, sstream, string
