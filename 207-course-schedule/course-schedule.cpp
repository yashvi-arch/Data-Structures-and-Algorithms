class Solution {
public:
    bool solve(int n,unordered_map<int,vector<int>>& adj,vector<int>& indegree){
        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            count++;

            for(int v:adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        return count==n;
    }

    bool canFinish(int numCourses,vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> adj;

        for(vector<int>& vec:prerequisites){
            int u=vec[0];
            int v=vec[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        return solve(numCourses,adj,indegree);
    }
};