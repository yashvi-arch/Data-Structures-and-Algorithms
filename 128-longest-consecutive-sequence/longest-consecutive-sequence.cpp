class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=1;
        long long cnt=1;
        if(nums.empty()){
            return 0;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }else if(nums[i]==nums[i-1]+1){
                cnt++;
            }else{
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};