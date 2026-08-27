class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]); //populate the pq
        }
        long long score=0;
        while(k--){
            int val=pq.top();
            pq.pop();
            score+=val;
            pq.push(ceil(val+2)/3);
        }
        return score;
        
    }
};