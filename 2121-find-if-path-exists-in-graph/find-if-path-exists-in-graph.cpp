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
        }else if(rank[xpar]<rank[ypar]){
            parent[xpar]=ypar;
        }else if(rank[xpar]>rank[ypar]){
            parent[ypar]=xpar;
        }else{
            parent[xpar]=ypar;
            rank[ypar]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto e:edges){
            uunion(e[0],e[1],parent,rank);
        }
        return find(source,parent)==find(destination,parent);
        

        
    }
};