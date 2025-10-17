class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool> &vis, int u){
        vis[u] = true;
        for(auto v : adj[u]){
            if(!vis[v]){
                dfs(adj,vis,v);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto c : connections){
            int u = c[0];
            int v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt - 1;
    }
};