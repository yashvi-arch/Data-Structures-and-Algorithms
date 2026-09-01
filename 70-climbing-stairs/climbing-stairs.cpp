class Solution {
public:
    int n;
    vector<int>dp;
    int solve(int i){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=solve(i+1)+solve(i+2);
    }
    int climbStairs(int n) {
        this->n=n;
        dp.assign(n+1,-1);
        return solve(0);
        
    }
};