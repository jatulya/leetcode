class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastreached = nums.size() - 1;
        for (int i=nums.size()-2; i>=0; i--)
            if (nums[i]+i >= lastreached)
                lastreached = i;
        return lastreached == 0;
    }
};
