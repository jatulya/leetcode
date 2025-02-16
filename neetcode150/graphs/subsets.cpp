class Solution {
    vector<vector<int>> output;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> set;
        recursion(0, set, nums, nums.size());
        return output;
    }
private:
    void recursion (int i, vector<int>& set, vector<int>& nums, int n){
        if (i==n){
            output.push_back(set);
            return;
        }

        set.push_back(nums[i]);
        recursion(i+1, set, nums, n);
        set.pop_back();
        recursion(i+1, set, nums, n);
    }
};
