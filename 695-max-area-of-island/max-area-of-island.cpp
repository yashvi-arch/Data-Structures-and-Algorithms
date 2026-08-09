class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col){
        int m=grid.size();
        int n=grid[0].size();
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==0){
            return 0; //out of bound case
        }
        int count=1; //there is a 1 already so count is initialised as 1 already
        grid[row][col]=0;
        count+=dfs(grid,row+1,col);
        count+=dfs(grid,row-1,col);
        count+=dfs(grid,row,col+1);
        count+=dfs(grid,row,col-1);
        return count; //returns the no of 1's present in all the four directions
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(grid,i,j)); //calc max area of 1's in the entire grid
                    
                }
            }
        }
        return ans;
        
    }
};