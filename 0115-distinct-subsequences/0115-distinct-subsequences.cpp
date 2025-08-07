class Solution {
public:
    int findWays(string s, string t, int i, int j, vector<vector<int>>& dp) {
        if(j<0) return 1; 
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = findWays(s,t,i-1,j-1,dp) + findWays(s,t,i-1,j,dp);
        return dp[i][j] = findWays(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        // idea : using recursion and memoization
        // start from both their end indexes, if equal either take the last index of t or not take
        // but always decrement index of s

        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return findWays(s,t,m-1,n-1,dp);
    }
};