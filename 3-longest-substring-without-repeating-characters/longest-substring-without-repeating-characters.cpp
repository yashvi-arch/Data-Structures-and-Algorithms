class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int ans=0;
        vector<int>res(128,-1);
        for(int r=0;r<n;r++){
            if(res[s[r]]>=l){
                l=res[s[r]]+1;
            }
            res[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};