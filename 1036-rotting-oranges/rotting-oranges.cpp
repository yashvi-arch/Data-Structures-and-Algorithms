class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        int min=0;
        queue<p>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j}); //rotten orange
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        while(!q.empty()){
            int N=q.size();
            while(N--){
                p curr=q.front();
                q.pop();
                int i=curr.first;
                int j=curr.second;
                for(vector<int>& dir:directions){
                    int newi=i+dir[0];
                    int newj=j+dir[1];
                    if(newi>=0 && newi<m && newj>=0 && newj<n && grid[newi][newj]==1){
                        grid[newi][newj]=2;
                        q.push({newi,newj});
                        fresh--;
                    }
                }
            }
            min++;
        }
        if(fresh==0){
            return (min-1);
        }
        return -1;
    }
};