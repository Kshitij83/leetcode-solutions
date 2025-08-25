class Solution {
public:
    // int findAns(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>>& dp) {
    //     if(ind==n) return 0;
    //     if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        // int len = findAns(ind+1,prev_ind,n,nums,dp);
        // if(prev_ind==-1 || nums[ind]>nums[prev_ind]) {
        //     len = max(len,1 + findAns(ind+1,ind,n,nums,dp));
        // }
    //     return dp[ind][prev_ind+1] = len;
    // }
    int lengthOfLIS(vector<int>& nums) {
        //Approach 2 : Tabulation
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--) {
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--) {
                int len = dp[ind+1][prev_ind+1];
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]) {
                    len = max(len,1 + dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind+1] = len;
            }
        }
        return dp[0][0];

        //Approach 1 : Memoization 
        // int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return findAns(0,-1,n,nums,dp);
    }
};