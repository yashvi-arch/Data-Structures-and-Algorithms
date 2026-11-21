class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int ans=INT_MAX;
        while(i+1<n){
            int a=nums[i];
            int b=nums[i+1];
            int temp=b;
            while(temp>0){
                a*=10;
                temp/=10;
            }
            int merged=a+b;
            ans=min(ans,merged);
            i+=2;
        }
        return ans;


    }
};