class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l=0,r = nums.size()-1, output=-1, mid;

        while(l<=r){
            mid = (l+r)/2;
            if (target>nums[mid]){
                l=mid+1;
            }
            else if (target<nums[mid]){
                r = mid -1;
            }
            else{
                output = mid;
                break;
            }
        }

        return output;
        
    }
};
