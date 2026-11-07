class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){

                if((row==0 || mat[row][col]>mat[row-1][col]) &&
                   (row==m-1 || mat[row][col]>mat[row+1][col]) &&
                   (col==0 || mat[row][col]>mat[row][col-1]) &&
                   (col==n-1 || mat[row][col]>mat[row][col+1])){
                    return {row,col};
                }
            }
        }
        return {};
    }
};