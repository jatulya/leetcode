class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area, max=0, l=0, r=heights.size()-1 ;

        while(l<r){
            area = min(heights[l], heights[r])*(r-l);
            if (area>max){
                max=area;
            }
            if (heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
            }
        }

        return max;

    }
};
