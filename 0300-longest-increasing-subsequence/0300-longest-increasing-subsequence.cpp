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
        //Approach 5 : Binary search (does not get actual answer but can get size)
        //idea : if incoming num is more than last elem then push
        //or else just replace the first greater elem than incoming with incoming
        int n = nums.size();
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++) {
            if(nums[i]>arr.back()) arr.push_back(nums[i]);
            else {
                auto ind = lower_bound(arr.begin(),arr.end(),nums[i]);
                *ind = nums[i];
            }
        }
        return arr.size();

        //Approach 4: Tabulation but used for printing the subsequence too
        // int n = nums.size();
        // vector<int> dp(n,1),hash(n,-1);
        // int maxi = 1;
        // int ind = -1;
        // for(int i=1;i<n;i++) {
        //     for(int j=0;j<i;j++) {
        //         if(nums[j]<nums[i] && dp[j]+1 > dp[i]) {
        //             hash[i] = j;
        //             dp[i] = dp[j] + 1;
        //             if(maxi < dp[i]) {
        //                 maxi = dp[i];
        //                 ind = i;
        //             }
        //         }
        //     }
        // }
        // if(ind==-1) cout<<nums[n-1]; 
        // while(ind!=-1) {
        //     cout<<nums[ind]<<" ";
        //     ind = hash[ind];
        // }
        // return maxi;


        //Approach 3 : Tabulation with SC - O(2*N)
        // int n = nums.size();
        // vector<int> prev(n+1,0),curr(n+1,0);
        // for(int ind=n-1;ind>=0;ind--) {
        //     for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--) {
        //         int len = prev[prev_ind+1];
        //         if(prev_ind==-1 || nums[ind]>nums[prev_ind]) {
        //             len = max(len,1 + prev[ind+1]);
        //         }
        //         curr[prev_ind+1] = len;
        //     }
        //     prev = curr;
        // }
        // return prev[0];

        //Approach 2 : Tabulation
        // int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // for(int ind=n-1;ind>=0;ind--) {
        //     for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--) {
        //         int len = dp[ind+1][prev_ind+1];
        //         if(prev_ind==-1 || nums[ind]>nums[prev_ind]) {
        //             len = max(len,1 + dp[ind+1][ind+1]);
        //         }
        //         dp[ind][prev_ind+1] = len;
        //     }
        // }
        // return dp[0][0];

        //Approach 1 : Memoization 
        // int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return findAns(0,-1,n,nums,dp);
    }
};