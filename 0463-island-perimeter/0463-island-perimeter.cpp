class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {-1,0,1,0};
        int perimeter = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    int incr = 4;
                    for(int k=0;k<4;k++) {
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1) incr--; 
                    }
                    perimeter += incr;
                }
            }
        }
        return perimeter;
    }
};