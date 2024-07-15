class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stck;
        int maxarea = 0;

        for (int i=0; i<heights.size(); i++){
            int start = i;
            while (!stck.empty() && stck.top().second > heights[i]){
                int height = stck.top().second;
                int index = stck.top().first;
                stck.pop();
                maxarea = max(maxarea, (i-index)*height);
                start = index;
            }
            stck.push({start,heights[i]});
        }

        while (!stck.empty()){
            int area = stck.top().second*(heights.size()-stck.top().first);
            maxarea = max(maxarea,area );
            stck.pop();
        } 

        return maxarea;
    }
};
