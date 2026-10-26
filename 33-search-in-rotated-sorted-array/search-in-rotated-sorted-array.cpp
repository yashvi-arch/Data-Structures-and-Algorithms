class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){ //left half sorted
                if(target>=nums[low] && target<=nums[mid]){
                    high=mid-1; //elimintate right half
                }else{
                    low=mid+1; //el lh
                }
            }else{
                if(target>nums[mid] && target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }

            }
        }
        return -1;
        
    }
};