class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0;
        int h=0;
        int ans=0;
        unordered_map<char,int>mpp;
        for(int h=0;h<n;h++){
            mpp[s[h]]++;

            while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
                ans+=(n-h);
                mpp[s[l]]--;
                l++;
            }
        }
        return ans;


    }
};