class Solution {
    bool isBipartite(vector<vector<int>>& adj, vector<int>& colored,int u,int color){
        colored[u] = color;
        for(auto v : adj[u]){
            if(colored[v] == -1){
                if(!isBipartite(adj,colored,v,!color))
                    return false;
            }
            else if(colored[v] == color)
                return false;
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> colored(n,-1);
        
        for(int i=0;i<n;i++){
            if(colored[i] == -1 && !isBipartite(adj,colored,i,0)){
                return false;
            }
        }
        return true;
    }
};