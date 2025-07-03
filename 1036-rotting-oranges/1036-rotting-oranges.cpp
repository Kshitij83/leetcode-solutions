class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {-1,0,1,0};
        int min = 0;
        while(!q.empty()) {
            int s = q.size();
            for(int i=0;i<s;i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0;j<4;j++) {
                    int nx = x+dx[j];
                    int ny = y+dy[j];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            min++;
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) return -1;
            }
        }
        return (min==0) ? min : min-1;
    }
};