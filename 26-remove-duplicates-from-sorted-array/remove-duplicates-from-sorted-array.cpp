class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    k--;
                    for(int p=j;p<n-1;p++){
                        nums[p]=nums[p+1];
                    }
                    n--;
                    j--;
                    
                }


            }
        }
        return k;
        
    }
};