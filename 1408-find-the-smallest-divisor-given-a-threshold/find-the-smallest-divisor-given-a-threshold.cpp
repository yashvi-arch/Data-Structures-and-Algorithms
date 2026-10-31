class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int div=low+(high-low)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                int res=ceil((double)nums[i]/div);
                sum+=res;
            }
            if(sum<=threshold){
                ans=div;
                high=div-1;
            }else{
                low=div+1;
            }
        }
        return ans;
        
    }
};