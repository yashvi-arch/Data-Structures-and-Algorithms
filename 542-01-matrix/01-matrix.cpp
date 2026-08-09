class Solution {
public:
    typedef pair<int,int> p;
    vector<vector<int>> direction{{-1,0},{1,0},{0,-1},{0,1}};
    queue<p> q;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> dist(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            pair<int,int> curr=q.front();
            q.pop();

            int row=curr.first;
            int col=curr.second;

            for(auto dir:direction){
                int nr=row+dir[0];
                int nc=col+dir[1];

                if(nr>=0 && nr<m && nc>=0 && nc<n && dist[nr][nc]==-1){
                    dist[nr][nc]=dist[row][col]+1;
                    q.push({nr,nc});
                }
            }
        }

        return dist;
    }
};