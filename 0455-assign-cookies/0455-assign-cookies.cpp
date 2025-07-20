class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int assigned = 0;
        int l = 0;
        int r = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<g.size() && r<s.size()) {
            if(g[l]<=s[r]) {
                l++;
                assigned++;
            }
            r++;
        }
        return assigned;
    }
};