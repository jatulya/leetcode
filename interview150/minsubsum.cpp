class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0, l=0, r=0, n = nums.size(), minlen=n+1;

        while(r<n){
            sum += nums[r];
            while (sum>=target){
                minlen = min(r-l+1, minlen);
                sum -= nums[l];
                l++;
            }
            r++;
        } 

        return minlen == n+1 ? 0 : minlen;
    }
};
