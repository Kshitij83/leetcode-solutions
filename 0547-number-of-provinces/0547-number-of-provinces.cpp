class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& isConnected) {
        vis[node] = 1;
        for(int i=0;i<isConnected.size();i++) {
            if(!vis[i] && isConnected[node][i]==1) dfs(i,vis,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // TC - O(N) + O(V+2E)
        int v = isConnected.size();
        vector<int> vis(v,0);
        int count = 0;
        for(int i=0;i<v;i++) {
            if(!vis[i]) {
                dfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
    }
};