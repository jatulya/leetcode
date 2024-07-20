class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size()==1)
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b) {
            if (a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        });

        int toErase = 0, maxend = intervals[0][1];
        for (int i=0; i<intervals.size()-1; i++)
            if (intervals[i][1] > intervals[i+1][0]){
                if (intervals[i][1] < intervals[i+1][1])
                    intervals[i+1] = intervals[i];
                toErase++;
            }
            
        return toErase;
    }
};
