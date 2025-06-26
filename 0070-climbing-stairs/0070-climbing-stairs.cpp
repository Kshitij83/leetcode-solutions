class Solution {
public:
    int findStairs(int n, vector<int>& dp) {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = findStairs(n-1,dp) + findStairs(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return findStairs(n,dp);
    }
};