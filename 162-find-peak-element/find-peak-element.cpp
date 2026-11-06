class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mid==0 && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(mid==n-1 && nums[mid]>nums[mid-1]){
                return mid;
            }
            if(mid>0 && mid<n-1 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(nums[mid]>nums[mid+1]){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};