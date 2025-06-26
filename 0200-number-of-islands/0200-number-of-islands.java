class Solution {
    public void dfs(int r, int c, char[][] grid, int[][] vis) {
        vis[r][c] = 1;
        int[] dc = {-1,0,1,0};
        int[] dr = {0,-1,0,1};
        for(int i=0;i<4;i++) {
            int nr = dr[i] + r;
            int nc = dc[i] + c;
            if(nr>=0 && nc>=0 && nr<grid.length && nc<grid[0].length && grid[nr][nc]=='1' && vis[nr][nc]==0) {
                dfs(nr,nc,grid,vis);
            }
        }
    }
    public int numIslands(char[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[][] vis = new int[r][c];
        int count = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j]=='1' && vis[i][j]==0) {
                    dfs(i,j,grid,vis);
                    count++;
                    System.out.println(i+" "+j+" "+count);
                }
            }
        } 
        return count;
    }
}