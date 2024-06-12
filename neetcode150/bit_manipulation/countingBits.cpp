class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        result[0] = 0;
        int pow2 = 1;

        for (int i=1; i<n+1; i++){
            if (pow2*2 == i){
                pow2 = i;
            }
            result[i] = 1 + result[i-pow2];
        }

        return result;
    }
};
