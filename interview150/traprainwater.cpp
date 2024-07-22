class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()==1)
            return 0;
        
        int water=0, l=0, r = height.size()-1, leftmax = height[l], rightmax = height[r];

        while(l<r){
            if (leftmax < rightmax){
                l++;
                leftmax = max(leftmax, height[l]);
                water += (leftmax - height[l]);
            }else{
                r--;
                rightmax = max(rightmax, height[r]);
                water += (rightmax - height[r]);
            }
        }
        return water;
        
    }
};
