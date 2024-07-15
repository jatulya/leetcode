class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int stepone = 0; //from one step before the current step
        int steptwo = 0;//from two steps before the current step
        int mincost = 0; //final answer
        //thus starting from the step with index 2
        for (int i=2; i<=cost.size(); i++){
            mincost = min(stepone+cost[i-1], steptwo+cost[i-2]);
            steptwo = stepone;
            stepone = mincost;
        }
        return mincost;
    }
};
