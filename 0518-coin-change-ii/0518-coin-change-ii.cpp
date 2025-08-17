class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long int>> dp(n,vector<unsigned long long int>(amount+1,0));
        for(int j=0;j<=amount;j++) {
            if(j%coins[0]==0) dp[0][j] = 1;
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<=amount;j++) {
                unsigned long long int take = 0;
                unsigned long long int notTake = dp[i-1][j];
                if(coins[i]<=j) take = dp[i][j-coins[i]];
                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};