class Solution {
public:
    int uniquePath(int i, int j, vector<vector<int>>& dp) {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = uniquePath(i,j-1,dp);
        int up = uniquePath(i-1,j,dp);
        return dp[i][j] = left + up;
    }
    int uniquePaths(int m, int n) {
        //dp approach, tc - O(n*m) , sc - O(n-1 + m-1) (Path length: stack space) + O(n*m) 
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniquePath(m-1,n-1,dp);


        //TC - O(2^M*N) , SC - O(PATH LENGTH) SPACE COMPLEXITY CONSISTS OF THE RECURSIVE CALL STACK
        // if(m==1 && n==1) return 1;
        // if(m==0 || n==0) return 0;
        // int left = uniquePaths(m,n-1);
        // int up = uniquePaths(m-1,n);
        // return left + up;
    }
};