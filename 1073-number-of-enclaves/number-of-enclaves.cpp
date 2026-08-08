class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col){
        int m=grid.size();
        int n=grid[0].size();
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==0){
            return;
        }
        grid[row][col]=0;
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                dfs(grid,0,j);
            }
            if(grid[m-1][j]==1){
                dfs(grid,m-1,j);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }
            if(grid[i][n-1]==1){
                dfs(grid,i,n-1);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};