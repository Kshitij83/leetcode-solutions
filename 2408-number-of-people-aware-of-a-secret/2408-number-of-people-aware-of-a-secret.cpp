//A(1,3,5) - > B()

class Solution {
public:
    //static int count = 1;
    // void findAns(int& count, int cur, int n, int delay, int forget, int mod) {
    //     if(cur+forget > n) {
    //         count = (count+1) % mod;
    //     }
    //     for(int i=cur+delay;i<cur+forget;i++) {
    //         if(i>n) break;
    //         findAns(count,i,n,delay,forget,mod);
            
    //     }
    // }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        long long share = 0, MOD = 1000000007;
        for (int t = 2; t <= n; t++) {
            if (t - delay > 0)
                share = (share + dp[t - delay] + MOD) % MOD;
            if (t - forget > 0)
                share = (share - dp[t - forget] + MOD) % MOD;
            dp[t] = share;
        }
        long long know = 0;
        for (int i = n - forget + 1; i <= n; i++)
            know = (know + dp[i]) % MOD;
        return (int)know;
    }
};
