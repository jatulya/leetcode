/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (!intervals.size()) return 0;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> minheap;
        minheap.push(intervals[0].end);

        for (int i=1; i<intervals.size(); i++){
            if (minheap.top() <= intervals[i].start)
                minheap.pop();
            minheap.push(intervals[i].end);              
        }

        return minheap.size();
    }
};
