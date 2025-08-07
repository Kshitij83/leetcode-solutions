class Solution {
public:
    int findWays(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j] = findWays(word1,word2,i-1,j-1,dp);
        return dp[i][j] = min(1 + findWays(word1,word2,i-1,j-1,dp), min(1 + findWays(word1,word2,i,j-1,dp),1 + findWays(word1,word2,i-1,j,dp)));
    }

    int minDistance(string word1, string word2) {
        // idea : dp memoization 
        // if match then f(i-1,j-1)
        // else f(i-1,j-1) (for replace), f(i-1,j) (for delete) and f(i,j-1) (for insert)
        //base cases if either index less than zero then return other index + 1 (this can either mean insert or delete)
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return findWays(word1,word2,m-1,n-1,dp);
    }
};