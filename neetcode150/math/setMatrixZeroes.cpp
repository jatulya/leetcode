class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fc=1, m = matrix.size(), n = matrix[0].size();
        int i, j;

        for( i=0; i<m; i++)
            for ( j=0; j<n; j++)
                if (!matrix[i][j]){
                    matrix[i][0] = 0;
                    if (!j) fc=0; //if first column has 0, then it should be 0
                    else matrix[0][j] = 0;
                }

        //making corresponding columns 0 except 1st column
        for (j=1; j<n; j++)
            if (!matrix[0][j])
                for(i=1; i<m; i++)
                    matrix[i][j]=0;

        //making corresponding rows 0
        for (i=0; i<m; i++)
            if (!matrix[i][0])
                for(j=1; j<n; j++)
                    matrix[i][j]=0;
        
        //making first column 0 if fc==0
        if (!fc)
            for(i=0; i<m; i++)
                 matrix[i][0]=0;
    }
};
