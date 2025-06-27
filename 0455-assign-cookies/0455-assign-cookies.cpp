class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        int count = 0;
        int i=0, j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<m && j<n) {
            if(g[i]<=s[j]) {
                i++;
                j++;
                count++;
            }
            else j++;
        }
        return count;
    }
};
