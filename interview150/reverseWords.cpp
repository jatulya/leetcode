class Solution {
public:
    string reverseWords(string s) {
        if (s.length()==1) return s;

        reverse(s.begin(),s.end());
        int l=0, r =0, i=0, n = s.length();
        while(i<n){
            //finding the spaces
            while(i<n && s[i]==' '){
                i++;
            }
            if (i==n) break; //if last point is reached
            while(i<n && s[i]!=' '){
                s[r++] = s[i++];
            }
            reverse(s.begin()+l, s.begin()+r);
            s[r++] = ' ';
            l = r;
            i++;
        }
        s.resize(r-1);
        return s;
    }
};
