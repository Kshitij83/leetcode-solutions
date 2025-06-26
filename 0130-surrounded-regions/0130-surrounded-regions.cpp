class Solution {
public:

    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& vis, int n, int m) {
        vis[x][y] = 1;
        if((x-1)>=0 && !vis[x-1][y] && board[x-1][y]=='O') dfs(x-1,y,board,vis,n,m);
        if((y-1)>=0 && !vis[x][y-1] && board[x][y-1]=='O') dfs(x,y-1,board,vis,n,m);
        if((x+1)<n && !vis[x+1][y] && board[x+1][y]=='O') dfs(x+1,y,board,vis,n,m);
        if((y+1)<m && !vis[x][y+1] && board[x][y+1]=='O') dfs(x,y+1,board,vis,n,m);
    }

    void solve(vector<vector<char>>& board) {
        //simple idea: from boundary, traverse and mark all O's connected to it
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            if(i==0 || i==n-1) {
                for(int j=0;j<m;j++) {
                    if(board[i][j]=='O' && !vis[i][j]) dfs(i,j,board,vis,n,m);
                }
            }
            else {
                if(board[i][0]=='O' && !vis[i][0]) dfs(i,0,board,vis,n,m);
                if(board[i][m-1]=='O' && !vis[i][m-1]) dfs(i,m-1,board,vis,n,m);
            }
        }
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) {
                if(board[i][j]=='O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};