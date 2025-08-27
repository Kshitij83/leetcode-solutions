class Solution {
public:
    // int matcher(int i, int j, string &s, string &p, int m, int n, vector<vector<int>>& dp) {
    //     if (j == n) return i == m; 

    //     if (dp[i][j] != -1) return dp[i][j];

    //     bool match = (i < m && (s[i] == p[j] || p[j] == '.'));

    //     if (j+1 < n && p[j+1] == '*') {
    //         return dp[i][j] = (matcher(i, j+2, s, p, m, n, dp) ||
    //                            (match && matcher(i+1, j, s, p, m, n, dp)));
    //     } else {
    //         return dp[i][j] = (match && matcher(i+1, j+1, s, p, m, n, dp));
    //     }
    // }

    bool isMatch(string s, string p) {
        // int m = s.size(), n = p.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return matcher(0, 0, s, p, m, n, dp);
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[n][m] = true;
        for(int i=n;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                bool match = (i < n && (s[i] == p[j] || p[j] == '.'));
                if(j+1 < m && p[j+1] == '*') {
                    dp[i][j] = (dp[i][j+2] || (match && dp[i+1][j]));
                }
                else {
                    dp[i][j] = (match && dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
