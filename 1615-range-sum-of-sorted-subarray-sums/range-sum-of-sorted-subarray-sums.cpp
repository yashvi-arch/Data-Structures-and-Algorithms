class Solution {
public:
    int M=1e9+7;
    typedef pair<int,int>p;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        int res=0;
        for(int cnt=1;cnt<=right;cnt++){
            auto v=pq.top();
            pq.pop();
            int sum=v.first;
            int idx=v.second;

            if(cnt>=left){
                res=(res+sum)%M;
            }
            int next_idx=idx+1;
            p next_pair; //new pair to be pushed
            if(next_idx<n){ //not out of bound h
                next_pair.first=sum+nums[next_idx];
                next_pair.second=next_idx;
                pq.push(next_pair);
            }
        }
        return res;

        
    }
};