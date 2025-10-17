class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    vector<int> cap;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        cap.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            rank[i] = 0;
            cap[i] = 1;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return;
        int uRank = rank[pu];
        int vRank = rank[pv];
        if(uRank >= vRank){
            parent[pv] = pu;
            if(uRank == vRank)
                rank[pu]++;
        }
        else
            parent[pu] = pv;
    }
    
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return;
        int uSize = cap[pu];
        int vSize = cap[pv];
        if(uSize >= vSize){
            parent[pv] = pu;
            cap[pv] += cap[pu];
        }
        else{
            parent[pu] = pv;
            cap[pu] += cap[pv];
        }
    }
    
    bool isSameComponent(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        return (pu == pv);
    }

    int getConnections(int n){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(parent[i] == i)
                cnt++;
        }
        return cnt;
    }
    
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        DisjointSet ds(n);
        for(auto c : connections){
            int u = c[0];
            int v = c[1];
            ds.unionByRank(u,v);
        }
        return ds.getConnections(n) - 1;
    }
};