class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int bit = 0, i=32;
        while (n && i){
            i -= 1;
            bit = n & 1;
            n = n >> 1;
            ans = ans | (bit << i);
        }
        return ans;
        
    }
};

/* bit = n&1 => gives the lsb of the number (any bit taken logical and with 1 gives the bit itself)
   n = n>>1 => shifts the number by one digit towards the right (or it can be taken as n//2 )
   bit<<i => we left shift the and bit towards the position at which it would be when reversed
   we take logical or of the previous answer with the current bit answer to get the combined answer

   let n = 18 ( = 000.....10010)
   at i = 3
   bit = 18 & 1 = 0
   n = 18 >> 9 = (000....1001)
   ans = 000..0

   at i = 30
   bit = 9 & 1 = 1
   n = 9>>1 = 4 = (00...100)
   bit << i = 1 <<30 = 0100......00
   ans = 000....00 | 0100...00 = 0100....00
*/
