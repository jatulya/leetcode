class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res;
        stack<int> st;
        int len = temp.size();
        
        for (int i=len-1; i>=0; i--){
            if (st.empty()){
                res.push_back(0);
                st.push(i);
            }
            else{
                while(!st.empty()){
                    if (temp[st.top()]>temp[i]){
                        res.push_back(st.top()-i);
                        st.push(i);
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if (st.empty()){
                    res.push_back(0);
                    st.push(i);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
