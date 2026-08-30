class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        if(mini>maxi){
            swap(maxi,mini);
        }
        int front=maxi+1;
        int back=n-mini;
        int both=mini+1+n-maxi;
        return min({front,back,both});


    }
};