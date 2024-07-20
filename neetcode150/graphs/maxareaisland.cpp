class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        for (int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                if (grid[i][j])
                    maxarea = max(maxarea, dfs(grid, i,j));
        return maxarea;
    }
private:
    int dfs(vector<vector<int>>& grid, int r, int c){       
        if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0)
            return 0;

        grid[r][c]=0;
        return 1 + dfs(grid,r+1,c) + dfs(grid,r-1,c) + dfs(grid,r,c+1) + dfs(grid,r,c-1);
    }
};
