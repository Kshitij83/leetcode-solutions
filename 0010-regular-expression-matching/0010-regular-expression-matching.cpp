class Solution {
public:
    int matcher(int i, int j, string &s, string &p, int m, int n, vector<vector<int>>& dp) {
        if (j == n) return i == m;  // both consumed?

        if (dp[i][j] != -1) return dp[i][j];

        bool match = (i < m && (s[i] == p[j] || p[j] == '.'));

        if (j+1 < n && p[j+1] == '*') {
            // either skip "x*" OR use it if match
            return dp[i][j] = (matcher(i, j+2, s, p, m, n, dp) ||
                               (match && matcher(i+1, j, s, p, m, n, dp)));
        } else {
            return dp[i][j] = (match && matcher(i+1, j+1, s, p, m, n, dp));
        }
    }

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return matcher(0, 0, s, p, m, n, dp);
    }
};
