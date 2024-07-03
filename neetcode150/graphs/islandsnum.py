class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        islands = 0

        def visit(r,c):
            if (r not in range(rows) or 
                c not in range(cols) or
                grid[r][c] == '0') :
                return 
            
            grid[r][c] = '0'
            visit(r, c+1)
            visit(r+1, c)
            visit(r-1,c)
            visit(r,c-1)

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    islands += 1
                    visit (i,j)

        return islands

        
