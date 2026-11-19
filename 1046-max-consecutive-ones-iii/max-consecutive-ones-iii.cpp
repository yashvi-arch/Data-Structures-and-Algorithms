class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int h=0;
        int zeroes=0;
        int ans=0;
        for(int h=0;h<n;h++){
            if(nums[h]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            ans=max(ans,h-l+1);
        }
        return ans;
        
    }
};