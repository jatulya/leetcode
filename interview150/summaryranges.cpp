class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> output;
        
        if (nums.size()!=0){
            int l=0, r=0;
            
            while (l<nums.size() && r<nums.size()){
               while (r<nums.size()-1 && (nums[r]+1== nums[r+1])){
                 r++;
                }
                
                if (l!=r)
                    output.push_back(to_string(nums[l])+"->"+to_string(nums[r])); 
                else output.push_back(to_string(nums[l]));

                l=r+1; r=l;
            }
        }
        return output;
    }
};
