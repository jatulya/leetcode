class Solution {
public:
    string addBinary(string a, string b) {
        if (a=="0")
            return b;
        if (b=="0")
            return a;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0, n = max(a.length(), b.length());
        string ans;
        
        for (int i=0; i<n; i++){
            int digitA = i>=a.length() ? 0 : a[i]-'0';
            int digitB = i>=b.length() ? 0 : b[i]-'0';
                
            ans = to_string(carry^digitA^digitB) + ans;
            carry = carry&digitA || carry&digitB || digitA&digitB;
        }

        if (carry)
            ans = "1" + ans;
        
        return ans;
        
    }
};
