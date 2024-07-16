class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        backtrack(nums, 0, output);
        return output;
    }
private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& output){
        if (start==nums.size()-1){
            output.push_back(nums);
            return;
        }
        for (int i=start; i<nums.size(); i++){
            swap(nums[start], nums[i]);
            backtrack(nums, start+1, output);
            swap(nums[i], nums[start]);
        }
    }
};
/*
  python code -> using permutations function
  class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return list(permutations(nums, len(nums)))
        
*/
