class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> modVals;
        vector<int> result;
        int s = nums.size();

        for (int i=0; i<nums.size(); i++){
            if (modVals.find(nums[i]) != modVals.end()){
                result.push_back(modVals[nums[i]]);
                result.push_back(i);
                break;
            }
            modVals[target - nums[i]] = i;
        }  

        return result;    
    }
}; 

