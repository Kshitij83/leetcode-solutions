class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis, int x, int y, int m, int n) {
        vis[x][y] = 1;
        //if(x==3 && y==4) cout<<"give me a cheer";
        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {-1,0,1,0};
        for(int i=0;i<4;i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1' && !vis[nx][ny]) dfs(grid,vis,nx,ny,m,n); 
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    dfs(grid,vis,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};