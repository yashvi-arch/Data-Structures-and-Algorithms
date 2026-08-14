class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(auto p:points){
            int x=p[0];
            int y=p[1];
            int dist=x*x+y*y;
            pq.push({dist,{x,y}});
        }
        vector<vector<int>> ans;
        while(k--){
            auto curr=pq.top();
            pq.pop();
            int x=curr.second.first;
            int y=curr.second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};