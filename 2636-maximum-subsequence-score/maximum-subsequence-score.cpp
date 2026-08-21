class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums1[i],nums2[i]});
        }
        auto lambda=[&](auto& p1,auto& p2){
            return p1.second>p2.second; //sorted based on descending order
        };
        sort(begin(vec),end(vec),lambda);

        long long ksum=0;
        long long result=0;

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<=k-1;i++){
            ksum+=vec[i].first;
            pq.push(vec[i].first);
        }
        result=ksum*vec[k-1].second;

        for(int i=k;i<n;i++){
            ksum+=vec[i].first-pq.top();
            pq.pop();
            pq.push(vec[i].first);

            result=max(result,ksum*vec[i].second);

        }
        return result;


        
    }
};