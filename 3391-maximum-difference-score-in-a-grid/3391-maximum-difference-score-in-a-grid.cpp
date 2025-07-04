class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> maxGrid(m,vector<int>(n));
        int ans = INT_MIN;
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                maxGrid[i][j] = grid[i][j];
                if(i+1 < m) maxGrid[i][j] = max(maxGrid[i][j],maxGrid[i+1][j]);
                if(j+1 < n) maxGrid[i][j] = max(maxGrid[i][j], maxGrid[i][j+1]);
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (i+1 < m) ans = max(ans, maxGrid[i+1][j] - grid[i][j]);
                if (j+1 < n) ans = max(ans, maxGrid[i][j+1] - grid[i][j]);  
            }
        }
        return ans;
    }
};