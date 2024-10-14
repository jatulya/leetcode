class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int val : s) {
            if (s.find(val - 1) == s.end()) {
                int count = 1;
                while (s.find(val + 1) != s.end()) {
                    count++;
                    val++;
                }
                longest = max(longest, count);
            }
        }
        
        return longest;
    }
};
