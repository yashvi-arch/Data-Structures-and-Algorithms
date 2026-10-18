class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                temp.push_back(0);
            }
        }
        nums.erase(remove(nums.begin(),nums.end(),0),nums.end());
        nums.insert(nums.end(),temp.begin(),temp.end());
        temp.clear();
        
    }
};