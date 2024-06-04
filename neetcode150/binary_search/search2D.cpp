class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int l=0, up=0, down = matrix.size()-1, r=matrix[0].size()-1;
        int mid;

        while (up<=down){
            mid = (up+down)/2;
            if (matrix[mid][r]<target){
                up = mid+1;
            }
            else if (matrix[mid][0]>target){
                down = mid-1;
            }
            else{
                break;
            }
        }

        if (up>down){
            return false;
        }

        int row = (up+down)/2;
        while(l<=r){
            mid = (l+r)/2;
            if (matrix[row][mid]==target){
                 return true;
            }
            else if (matrix[row][mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return false;

    }
};
