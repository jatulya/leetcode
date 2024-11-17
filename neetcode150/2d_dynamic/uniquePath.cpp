class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> belowRow (n, 1);

        for(int i=m-2; i>=0;i--){
            vector<int> curr (n, 1);
            for(int j=n-2;j>=0;j--)
                curr[j] = curr[j+1] + belowRow[j];
            belowRow = curr;
        }
        
        return belowRow[0];
    }
};
