class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()==1) return 0;

        int jumps = 0, rangeend = 0, currend = 0, n = nums.size();

        for (int i=0; i<n; i++){
            rangeend = max(rangeend, i+nums[i]);

            if (i==currend){
                jumps++;
                currend = rangeend;
                if (currend>= n-1)
                    break;
            }
        }

        return jumps;
    }
};
