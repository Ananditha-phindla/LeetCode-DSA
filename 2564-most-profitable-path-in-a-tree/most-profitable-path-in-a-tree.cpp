class Solution {
public:
    int ans = INT_MIN;
    bool bobpath(vector<vector<int>>&adj,int node,int steps,vector<int>&bobsteps,int parent){
        bobsteps[node] = steps;
        if(node == 0)
            return true;
        for(auto v : adj[node]){
            if(v != parent){
                if(bobpath(adj,v,steps+1,bobsteps,node))
                    return true;
            }
        }
        bobsteps[node] = -1;
        return false;
    }
    
    void AlicePath(vector<vector<int>>&adj,int node,int steps,vector<int>&bobsteps,int parent,int score,vector<int>&amount){
        if(bobsteps[node] == -1 || steps < bobsteps[node])
            score += amount[node];
        else if(bobsteps[node] == steps)
            score += (amount[node]/2);
        if(adj[node].size() == 1 && node != 0){
            ans = max(ans,score);
            cout << node << endl;
            return;
        }
        for(auto v : adj[node]){
            if(v != parent){
                AlicePath(adj,v,steps+1,bobsteps,node,score,amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        ans = INT_MIN;
        int n = edges.size();
        vector<vector<int>>adj(n+1);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>bobsteps(n+1,-1);
        bobpath(adj,bob,0,bobsteps,-1);
        AlicePath(adj,0,0,bobsteps,-1,0,amount);
        return ans;
    }
};