class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, mul=1;
        vector<int> output(nums.size(), 0);
        vector<int> index0;

        for (i=0; i<nums.size(); i++){
            if (nums[i]!=0){
                mul *= nums[i];
            }
            else{
                index0.push_back(i);
            }
        }

        if (index0.empty()){
            for (i=0; i<nums.size(); i++){
                output[i] = mul/nums[i];
            }
        } else if (index0.size() == nums.size() ||index0.size() > 1 ){
            return output;
        } 
        else {
            for (int k : index0){
                output[k] = mul;
            }
        }

        return output;
    }
};
