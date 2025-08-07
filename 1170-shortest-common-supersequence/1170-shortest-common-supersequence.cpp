class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // for(int i=0;i<=m;i++) {
        //     for(int j=0;j<=n;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        string c;
        int i = m, j = n;
        while((i>=0 && j>0) || (i>0 && j>=0)) {
            int cur = dp[i][j];
            while(i>0 && j>0 && str1[i-1]==str2[j-1]) {
                c = str1[i-1] + c;
                i--;
                j--;
            }
            while(i>0 && dp[i-1][j]==cur) {
                c = str1[i-1] + c; 
                i--;
            }
            while(j>0 && dp[i][j-1]==cur) {
                c = str2[j-1] + c;
                j--;
            }
        }
        // i=0;
        // j=0;
        // int k = 0;
        // while(i<m && j<n) {
        //     char cur = c[k];
        //     while(i<m && cur!=str1[i]) {
        //         c.insert(k,1,str1[i]);
        //         i++;
        //         k++;
        //     }
        //     while(j<n && cur!=str2[j]) {
        //         c.insert(k,1,str2[j]);
        //         j++;
        //         k++;
        //     }
        //     while(i<m && j<n && k<c.size() && str1[i]==c[k] && str2[j]==c[k]) {
        //         i++;
        //         j++;
        //         k++;
        //     }
        // }
        // if(i<m) c.append(str1,i,m);
        // else c.append(str2,j,n);
        return c;
    }
};