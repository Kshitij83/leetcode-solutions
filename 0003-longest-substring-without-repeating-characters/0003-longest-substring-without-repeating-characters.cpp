class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = 0;
        for(int i=0;i<s.size();i++){
            string sub = "";
            int hash[256] = {0};
            for(int j=i;j<s.size();j++){
                if(hash[s[j]]) break;
                sub += s[j];
                hash[s[j]] = 1;
                n = max(n,j-i+1);
            }
        }
        return n;
    }
};