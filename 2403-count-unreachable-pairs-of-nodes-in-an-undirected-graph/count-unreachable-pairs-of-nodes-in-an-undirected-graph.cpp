class Solution {
public:
    int find(int i,vector<int>& parent){
        if(i==parent[i]){
            return i;
        }else{
            return parent[i]=find(parent[i],parent);
        }
    }
    void uunion(int x,int y,vector<int>& parent,vector<int>& rank){
        int xpar=find(x,parent);
        int ypar=find(y,parent);
        if(xpar==ypar){
            return;
        }
        if(rank[xpar]<rank[ypar]){
            parent[xpar]=ypar;
        }
        if(rank[ypar]<rank[xpar]){
            parent[ypar]=xpar;
        }else if(rank[xpar]==rank[ypar]){
            parent[xpar]=ypar;
            rank[ypar]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto& vec:edges){
            int u=vec[0];
            int v=vec[1];
            uunion(u,v,parent,rank);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int baap=find(i,parent);
            mp[baap]++;
        }
        long long result=0;
        long long remaining=n;
        for(auto& it:mp){
            long long size=it.second;
            result+=(size)*(remaining-size);
            remaining-=size;
        }
        return result;
        
    }
};