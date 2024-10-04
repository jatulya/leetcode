class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int op = nums[0], currMax=1, currMin = 1;

        for (const auto& n: nums){
            int possMax = n*currMax, possMin = n*currMin;
            currMax = max(max(possMax, possMin), n);
            currMin = min(min(possMax, possMin), n);
            op = max(currMax, op);

        }
        
        return op;
    }
};
