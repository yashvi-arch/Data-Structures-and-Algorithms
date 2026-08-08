class Solution {
public: 
    void dfs(vector<vector<char>>& board,int row,int col){
        int m=board.size();
        int n=board[0].size();
        if(row<0 || row>=m || col<0 || col>=n || board[row][col]!='O'){
            return;
        }
        board[row][col] = 'S';
        dfs(board,row+1,col);
        dfs(board,row-1,col);
        dfs(board,row,col+1);
        dfs(board,row,col-1);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                //mark safe
                dfs(board,0,j);
            }
            if(board[m-1][j]=='O'){
                //mark safe
                dfs(board,m-1,j);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                //safe
                dfs(board,i,0);
            }
            if(board[i][n-1]=='O'){
                //safe
                dfs(board,i,n-1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='S'){
                    board[i][j]='O';
                }
            }
        }
        
    }
};