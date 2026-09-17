class Solution {
public:
    void bfs(vector<vector<int>>& isConnected,unordered_map<int,vector<int>>& adj,vector<bool>& visited,int u){
        queue<int>q;
        q.push(u);
        visited[u]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int& v:adj[curr]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(isConnected,adj,visited,i);
                count++;
            }
        }
        return count;
        
    }
};