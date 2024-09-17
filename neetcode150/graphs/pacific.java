class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length, n = heights[0].length;

        if (m==0 || n==0)
            return new ArrayList<>();
        
        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n - 1, m, n);
        }      
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m - 1, j, m, n);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (pacific[i][j] && atlantic[i][j]) 
                    result.add(new ArrayList<>(List.of(i, j)));

        return result;                                 
    }

    static int[] dirs = {-1, 0, 1, 0, -1};
    private void dfs(int[][] heights, boolean[][] ocean, int r, int c, int m, int n){
        ocean[r][c] = true;
        
        for(int i=0; i<4; i++){
            int nr = r + dirs[i];
            int nc = c + dirs[i+1];
            
            if (nr>=0 && nr<m && nc>=0 && nc<n && !ocean[nr][nc] && heights[r][c] <= heights[nr][nc])
                dfs(heights, ocean, nr, nc, m, n);
        }

    }
}
