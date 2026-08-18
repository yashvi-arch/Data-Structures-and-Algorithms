class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int temp=0;
        int ans=0;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k--){
            temp=pq.top();
            pq.pop();
            temp=temp-floor(temp/2);
            pq.push(temp);
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
        
        
    }
};