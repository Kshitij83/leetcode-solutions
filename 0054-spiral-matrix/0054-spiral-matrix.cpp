class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n1 = matrix.size();
        int n2 = matrix[0].size();
        int top = n1-2;
        int right = n2;
        int bottom = n1-1;
        int left = n2-1;
        int i = 0;
        int j = -1;
        while(res.size()<n1*n2){
            int r = right;
            int l = left;
            int b = bottom;
            int t = top;
            while(r>0 && res.size()<n1*n2){
                j++;
                res.push_back(matrix[i][j]);
                r--;
            }
            while(b>0 && res.size()<n1*n2){
                i++;
                res.push_back(matrix[i][j]);
                b--;
            }
            while(l>0 && res.size()<n1*n2){
                j--;
                res.push_back(matrix[i][j]);
                l--;
            }
            while(t>0 && res.size()<n1*n2){
                i--;
                res.push_back(matrix[i][j]);
                t--;
            }
            left-=2;
            right-=2;
            bottom-=2;
            top-=2;
        }
        return res;
    }
};