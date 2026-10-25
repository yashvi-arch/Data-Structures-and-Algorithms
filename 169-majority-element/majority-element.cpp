class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int test=floor(n/2);
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }else{
                cnt=1;
            }
            if(cnt>test){
                return nums[i];

            }

        }
        return nums[0];
        
    }
};