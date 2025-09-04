class Solution {
public:
    int findAns(int i,int j,vector<int>& cuts,vector<vector<int>>& dp) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minCost = 1e9;
        for(int ind=i;ind<=j;ind++) {
            int cost = cuts[j+1] - cuts[i-1] + findAns(i,ind-1,cuts,dp) + findAns(ind+1,j,cuts,dp);
            minCost = min(minCost,cost);
        }
        return dp[i][j] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        return findAns(1,c,cuts,dp);
    }
};