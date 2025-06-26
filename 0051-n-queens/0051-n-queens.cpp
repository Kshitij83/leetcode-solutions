class Solution {
public:

    // bool isSafe(int row,int col,vector<string>& board,int n) {
    //     int duprow = row;
    //     int dupcol = col;
    //     while(col>=0) {
    //         if(board[row][col]=='Q') return false;
    //         col--;
    //     }
    //     row = duprow;
    //     col = dupcol;
    //     while(row>=0 && col>=0) {
    //         if(board[row][col]=='Q') return false;
    //         row--;
    //         col--;
    //     }
    //     row = duprow;
    //     col = dupcol;
    //     while(row<n && col>=0) {
    //         if(board[row][col]=='Q') return false;
    //         row++;
    //         col--;
    //     }
    //     return true;
    // }

    // void solve(int col, vector<string>& board, vector<vector<string>>& ans,int n) {
    //     if(col==n) {
    //         ans.push_back(board);
    //         return;
    //     }
    //     for(int row=0;row<n;row++) {
    //         if(isSafe(row,col,board,n)) {
    //             board[row][col] = 'Q';
    //             solve(col+1,board,ans,n);
    //             board[row][col] = '.';
    //         }
    //     }
    // }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans,int n,
    vector<int>& leftrow,vector<int>& upperdiagonal,vector<int>& lowerdiagonal) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) {
            if(leftrow[row]==0 && upperdiagonal[n-1 + col-row]==0 && lowerdiagonal[row+col]==0) {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperdiagonal[n-1 + col-row] = 1;
                lowerdiagonal[row+col] = 1;
                solve(col+1,board,ans,n,leftrow,upperdiagonal,lowerdiagonal);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperdiagonal[n-1 + col-row] = 0;
                lowerdiagonal[row+col] = 0;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        //approach 2: using slight optimization techniques for leftrows, upper diagonals and lower diagonals
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) {
            board[i] = s;
        }
        vector<int> leftrow(n,0);
        vector<int> upperdiagonal(2*n-1,0);
        vector<int> lowerdiagonal(2*n-1,0);
        solve(0,board,ans,n,leftrow,upperdiagonal,lowerdiagonal);
        return ans;


        //approach 1: basic simple without any optimization techniques
        // vector<vector<string>> ans;
        // vector<string> board(n);
        // string s(n,'.');
        // for(int i=0;i<n;i++) {
        //     board[i] = s;
        // }
        // solve(0,board,ans,n);
        // return ans;
    }
};