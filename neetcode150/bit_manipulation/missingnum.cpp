class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int highest = 0, sum=0;
        for (int n: nums)
            sum += n;
        
        int n = nums.size();
        int fullsum = ((n*n)+n)/2;
        cout<<fullsum<<' '<<highest<<' '<<sum;
        return fullsum - sum;
    }
};
