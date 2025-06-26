class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        long long int d = -1;
        while(!q.empty()) {
            int s = q.size();
            for(int i=0;i<s;i++) {
                int node = q.front();
                q.pop();
                for(int i : adj[node]) {
                    if(!vis[i]) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            d++;
        }
        long long int mod = 1e9 + 7;
        long long int ans = powermod(2,d-1,mod);
        cout<<d;
        return ans;
                
    }
    long long int powermod(long long int a, long long int ex, long long int p) {
        long long int result = 1;
        long long int x = ex;
        while(x>0) {
            if(x%2 == 1) {
                result = (result * a * 1LL) % p;
                x--;
            }
            a = (a * a * 1LL) % p;
            x /= 2;
        } 
        return result;
    }
};