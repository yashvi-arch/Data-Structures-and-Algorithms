class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int n=nums.size();
        int j=0;
        int sum=0;
        int ans=0;
        if(goal<0) return 0;
        for(int i=0;i<n;i++){
            sum+=nums[i]; //first find out the whole array sum
            while(sum>goal){ //jabtak sum>goal hai
                sum-=nums[j]; //hatate rho aur ptr aage move krte rho
                j++;//shrinking the window
            }
            ans+=(i-j+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums,int goal){
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};