class Solution {
public:
    bool isHappy(int n) {

        int temp=n, d, s;
        vector<int> sums;

        while(true){
            s=0;
            while(temp>0){
                d = temp%10;
                s += d*d;
                temp /= 10;
            }

            if (s==1){
                return true;
            }
            else{
                if (find(sums.begin(), sums.end(), s) != sums.end()){
                    return false;
                }
                else{
                    sums.push_back(s);
                    temp = s;
                }
            }
        }
        
    }
};
