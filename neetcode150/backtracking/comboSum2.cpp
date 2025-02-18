class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        result.clear(); 
        vector<int> vals;
        cout<<candidates[0];
        dfs(candidates, 0, target, vals);
        return result;
    }
    
private:
    void dfs(vector<int>& nums, int index, int target, vector<int>& list){
        if (!target)
            result.push_back(list);

        for(int i=index; i<nums.size() && nums[i]<=target; i++){
            if (i!=index && nums[i]==nums[i-1]) 
                continue;
            
            list.push_back(nums[i]);
            dfs(nums, i+1, target - nums[i], list );
            list.pop_back();
        }
    }
};
