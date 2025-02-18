class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {     
        int m = grid.size(), n = grid[0].size(), days=0;
        setInitVals(grid, m, n);

        while(!indicesOfTwo.empty() && countOne>0){
            days++;
            bfs(grid, m, n);
        }

        return countOne ?  -1 : days;
    }

private:
    queue<pair<int, int>> indicesOfTwo;
    int countOne = 0;
    int dirs[5] = {-1, 0, 1, 0, -1};
    
    void setInitVals(vector<vector<int>>& grid, int m, int n){
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if (grid[i][j] == 2)
                    indicesOfTwo.push({i,j});
                else if (grid[i][j])
                    countOne++;
        }
    }

    void bfs(vector<vector<int>>& grid, int m, int n){
        int i= indicesOfTwo.size();
        while(i>0)
        {
            pair<int, int> index = indicesOfTwo.front();
            indicesOfTwo.pop();

            for (int k=0; k<4; k++){
                int r = dirs[k]+index.first;
                int c = dirs[k+1]+index.second;

                if (r<0 || r == m || c<0 || c==n || grid[r][c]!=1)
                    continue;
                
                grid[r][c]=2;
                indicesOfTwo.push({r,c});
                countOne--;
            }
            i--;
        }
    }
};
