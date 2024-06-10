class Solution {
public:
    int hammingWeight(int n) {
        int bits1 = 0;
        
        while (n){
            bits1 += n%2;
            n = n >> 1;
        }

        return bits1;
    }
};

//n >> 1 => this is right shift operation done on the binary bits of the number n
//by taking right shift, we can access the bit next to the lsb
// for eg -> 10011 >> 1 = 1001; 1001 >> 1 = 100
//accessing the lsb can be done by n%2
