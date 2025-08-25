class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i = 0, j = 0;
        int n = mat.size();
        int m = mat[0].size();
        int req = n*m;
        while(ans.size()!=req) {
            while(i>=0 && j<m) {
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(j<m) i=0;
            else {
                i+=2;
                j--;
            }
            while(j>=0 && i<n) {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            if(i<n) j=0;
            else {
                i--;
                j+=2;
            }
        }
        return ans;
    }
};