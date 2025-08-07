class Solution {
public:
    // int findWays(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
    //     if(j<0) return 1; 
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]) return dp[i][j] = findWays(s,t,i-1,j-1,dp) + findWays(s,t,i-1,j,dp);
    //     return dp[i][j] = findWays(s,t,i-1,j,dp);
    // }
    int numDistinct(string s, string t) {
        //idea : tabulation (take dp[m+1][n+1])
        //because in 0th column store 1 as we reached end of t
        //and in 0th row store 0 as we reached end of s
        //copy paste the recurrence from memoization

        int m = s.size();
        int n = t.size();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;i++) {
            dp[i][0] = 1;
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=min(n,i);j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int) dp[m][n];


        // idea : using recursion and memoization
        // start from both their end indexes, if equal either take the last index of t or not take
        // but always decrement index of s

        // int m = s.size();
        // int n = t.size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return findWays(s,t,m-1,n-1,dp);
    }
};