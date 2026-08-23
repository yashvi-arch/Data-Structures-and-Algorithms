class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>>pq;
        vector<string>ans(n);
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        int cnt=1;
        while(!pq.empty()){
            auto [marks,idx]=pq.top();
            pq.pop();
            if(cnt==1)
                ans[idx]="Gold Medal";
            else if(cnt==2)
                ans[idx]="Silver Medal";
            else if(cnt==3)
                ans[idx]="Bronze Medal";
            else
                ans[idx]=to_string(cnt);
            cnt++;
        }
        return ans;
    }
};