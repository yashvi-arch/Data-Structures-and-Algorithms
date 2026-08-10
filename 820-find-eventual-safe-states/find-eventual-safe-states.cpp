class Solution {
public:
    bool iscycledfs(vector<vector<int>>& adj,int u,vector<int>& visited,vector<int>& inrecursion){
        visited[u]=true;//initially
        inrecursion[u]=true;
        for(int& v:adj[u]){ //every node visit
            if(visited[v]==false && iscycledfs(adj,v,visited,inrecursion)){
                return true; //cycle hai
            }else if(inrecursion[v]==true){
                return true; //visited h aur rec me bhi h to cycle h
            }
        }
        inrecursion[u]=false;
        return false; //aur false ki nhi mila cycle
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>visited(n,false);
        vector<int>inrecursion(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                iscycledfs(adj,i,visited,inrecursion);
            }
        }
        vector<int>safenodes;
        for(int i=0;i<n;i++){
            if(inrecursion[i]==false){
                safenodes.push_back(i);
            }
        }
        return safenodes;

        
    }
};