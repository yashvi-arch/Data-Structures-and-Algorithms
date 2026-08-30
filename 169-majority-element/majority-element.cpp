class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++; //freq store krli map mein
        }
        int ans=0;
        int maxi=0;
        for(auto it:freq){
            if(it.second>maxi){
                maxi=it.second;
                ans=it.first;
            }
        }
        return ans;
        
    }
};