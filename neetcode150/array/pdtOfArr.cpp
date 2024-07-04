class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int n = nums.size(), i;

        output.push_back(1);
        for (i=1; i<n; i++)
            output.push_back(output[i-1]*nums[i-1]);

        int mul=1;
        for (i=n-1; i>=0; i--){
            output[i]*=mul;
            mul*=nums[i];
        }

        return output;
    }
};
