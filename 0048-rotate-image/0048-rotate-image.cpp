class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>> resmatrix(n,vector<int>(n));
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix.size();j++){
        //         resmatrix[j][matrix.size()-i-1]=matrix[i][j];
        //     }
        // }
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix.size();j++){
        //         cout<<resmatrix[i][j]<<" ";

        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};