class Solution {
public:
    bool checkPossible(string& s1, string& s2) {
        if(s2.size() != s1.size() + 1) return false;
        int i = 0, j = 0;
        while(j<s2.size()) {
            if(i<s1.size() && s1[i]==s2[j]) {
                i++;
                j++;
            }
            else j++;
        }
        if(i==s1.size() && j==s2.size()) return true;
        return false;
    }
    static bool comp(string& s1, string& s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(checkPossible(words[j],words[i]) && dp[i]<1+dp[j]) {
                    dp[i] = 1 + dp[j];
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};