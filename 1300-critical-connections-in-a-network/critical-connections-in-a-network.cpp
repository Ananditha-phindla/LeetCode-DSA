class Solution {
    void dfs(int node, vector<vector<int>> &adj,vector<int>& time, vector<int> &low, vector<vector<int>> &ans, vector<bool> &vis, int& timer, int parent){
        vis[node] = true;
        low[node] = timer;
        time[node] = timer;
        timer++;
        for(auto v : adj[node]){
            if(v == parent)
                continue;
            if(!vis[v]){
                dfs(v,adj,time,low,ans,vis,timer,node);
                low[node] = min(low[node],low[v]);
                if(low[v] > time[node]){
                    ans.push_back({node,v});
                }
            }
            else{
                low[node] = min(low[node],low[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto c : connections){
            int u = c[0];
            int v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time(n,0);
        vector<int> low(n,n+1);
        vector<bool> vis(n,false);
        vector<vector<int>> ans;
        int timer = 1;
        dfs(0,adj,time,low,ans,vis,timer,-1);

        return ans;
    }
};