class Solution {
public:
    void bfs(int x,int y,vector<vector<int>>& vis,vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y] = 1;
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()) {
            int n1 = q.front().first;
            int m1 = q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++) {
                for(int j=-1;j<=1;j++) {
                    if(abs(i+j)==1) {
                        int nrow = n1 + i;
                        int crow = m1 + j;
                        if(nrow>=0 && crow>=0 && nrow<n && crow<m && !vis[nrow][crow] && grid[nrow][crow]=='1') {
                            q.push({nrow,crow});
                            vis[nrow][crow] = 1;
                        } 
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        //TC - O(N^2) , SC - O(N^2)
        //idea : traverse all elements and if it is 1, then start doing bfs or dfs traversals(same like number of provinces)
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int islands = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    bfs(i,j,vis,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};