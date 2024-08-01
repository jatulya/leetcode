class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, curr = prices[0];

        for(int i = 1;i<prices.size(); i++){
            if(curr < prices[i]){
                max += prices[i] - curr;
            }
            curr = prices[i];
        }

        return max;
    }
};
