class Solution {
public:
    // int findAns(int i,int j,vector<int>& cuts,vector<vector<int>>& dp) {
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int minCost = 1e9;
    //     for(int ind=i;ind<=j;ind++) {
    //         int cost = cuts[j+1] - cuts[i-1] + findAns(i,ind-1,cuts,dp) + findAns(ind+1,j,cuts,dp);
    //         minCost = min(minCost,cost);
    //     }
    //     return dp[i][j] = minCost;
    // }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        for(int i=c;i>=1;i--) {
            for(int j=i;j<=c;j++) {
                if(i>j) continue;
                int mincost = 1e9;
                for(int k=i;k<=j;k++) {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]; 
                    mincost = min(mincost,cost);
                }
                dp[i][j] = mincost;
            }
        }
        return dp[1][c];
    }
};