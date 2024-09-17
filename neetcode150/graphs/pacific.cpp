class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size(), i, j;
        if (!m) return {};

        vector<vector<int>> pacific(m, vector<int>(n, 0)), atlantic(m, vector<int>(n, 0)), result;

        for(i=0; i<m; i++){
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n-1, m, n);
        }
        for(j=0; j<n; j++){
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m-1, j, m, n);
        }

        for(i=0; i<m; i++)
            for(j=0; j<n; j++){
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
            }
        return result;
        
    }
private:
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1,0}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int r, int c, int& m, int &n){
        if (ocean[r][c]) return;

        ocean[r][c] = 1; //marked visited as well as reachable
        for(auto& dir: dirs){
            int nr = dir[0] + r;
            int nc = dir[1] + c;
            if (nr >= 0 && nr<m && nc>=0 && nc<n && heights[r][c] <= heights[nr][nc])
                dfs(heights, ocean, nr, nc, m, n);
        }
    }
};
