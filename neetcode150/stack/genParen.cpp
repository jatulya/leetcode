class Solution {
public:

    void gen(int n, vector<string> &vals, int open, int close, string st){
        if (st.length() == n*2){
            vals.push_back(st);
        }
        if (open < n){
            st += "(";
            gen(n, vals, open+1, close, st);
            st.pop_back();
        }
        if (close < open ){
            st += ")";
            gen(n, vals, open, close+1, st);
            st.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {        
        vector<string> res;
        gen(n, res, 0, 0, "");
        return res;
    }
};
