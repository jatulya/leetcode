class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int r, c, k;
        char cell;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> squares;
        unordered_set<char> row;

        for (r=0; r<9; r++){
            for(c=0;c<9; c++){
                  cell = board[r][c];
                  
                  if (cell=='.'){
                    continue;
                  }

                  k = (r/3)*3 + c/3;
                  
                  if (find(cols[c].begin(), cols[c].end(), cell)!= cols[c].end()
                    ||find(squares[k].begin(), squares[k].end(), cell)!= squares[k].end() 
                    || find(row.begin(), row.end(), cell)!= row.end()){
                        return false;
                  }

                  cols[c].insert(cell);
                  row.insert(cell);
                  squares[k].insert(cell);
            }
            row.clear();
        }

        return true;
    }
};
