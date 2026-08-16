class Solution {
public:
    vector<int> solve(int n,unordered_map<int,vector<int>>& adj,vector<int>& indegree){
        queue<int>q;
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();

            ans.push_back(u);

            for(int v:adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(ans.size()!=n){
            return {};
        }
        return ans;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>>adj;
        for(vector<int>& vec:prerequisites){
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        return solve(numCourses,adj,indegree);

        
    }
};