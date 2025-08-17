class Solution {
public:
    int findTargetSumWays(vector<int>& num, int target) {
        //idea : solve it like finding ways to partition the nums into 2 subsets whose difference gives target
        int totalsum = accumulate(num.begin(),num.end(),0);
        int n = num.size();
        if(totalsum<target || (totalsum-target)%2) return 0;
        totalsum = (totalsum-target)/2;
        vector<vector<int>> dp(n,vector<int>(totalsum+1,0));
        if(num[0]==0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(num[0]!=0 && num[0]<=totalsum) dp[0][num[0]] = 1;
        for(int i=1;i<n;i++) {
            for(int sum=0;sum<=totalsum;sum++) {
                int take = 0;
                int notTake = dp[i-1][sum];
                if(num[i]<=sum) take = dp[i-1][sum-num[i]];
                dp[i][sum] = take + notTake;
            }
        }
        return dp[n-1][totalsum];
    }
};