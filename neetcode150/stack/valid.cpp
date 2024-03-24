#include <iostream>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char popped;

        unordered_map<char, char> b;
        b['}'] = '{';
        b[']'] = '[';
        b[')'] = '(';

        for (char a : s){
            if (a == '(' || a=='[' || a=='{')
                st.push(a);
            else{
                if (st.empty())
                    return false;
                popped = st.top();
                if (b[a] != popped)
                    return false;
                st.pop();
            }
        }

        if (st.empty())
            return true;
        else 
        return false;
    }
};

