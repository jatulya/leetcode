class Solution {
public:
    vector<vector<int>> output;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int> list;
       sort(nums.begin(), nums.end());
       recur(nums, list, 0);
       return output;
    }
    
private:
    void recur(vector<int>& nums, vector<int>& list, int i){
        if (i>=nums.size()){
            output.push_back(list);
            return;
        }

        list.push_back(nums[i]);
        recur(nums, list, i+1);
        
        list.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        recur(nums, list, i+1);
    }

};
