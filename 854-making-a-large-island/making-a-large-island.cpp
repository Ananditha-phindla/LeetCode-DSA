class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    vector<int> cap;
public :
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        cap.resize(n+1);
        for(int i=0;i<n+1;i++){
            rank[i] = 0;
            parent[i] = i;
            cap[i] = 1;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return;
        int urank = rank[pu];
        int vrank = rank[pv];
        if(urank >= vrank){
            parent[pv] = pu;
            if(urank == vrank)
                rank[pu]++;
        }
        else{
            parent[pu] = pv;
        }
    }
    
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return;
        int usize = cap[pu];
        int vsize = cap[pv];
        if(usize >= vsize){
            parent[pv] = pu;
            cap[pu] += cap[pv];
        }
        else{
            parent[pu] = pv;
            cap[pv] += cap[pu];
        }
    }
    
    bool isSameComponent(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        return pu == pv;
    }

    int getComponentSize(int node){
        return cap[node];
    }

};

class Solution {
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        bool isZero = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int curr = i*n+j;
                    for(int k=0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj]){
                            int adjNode = ni * n + nj;
                            ds.unionBySize(curr,adjNode);
                        }
                    }
                }
                else
                    isZero = true;
            }
        }

        if(!isZero)
            return n*n;
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    continue;

                unordered_set<int> parents;
                for(int k=0;k<4;k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >=0 && ni < n && nj >=0 && nj < n && grid[ni][nj]){
                        int adjNode = ni * n + nj;
                        parents.insert(ds.findParent(adjNode));
                    }
                }
                int currSum = 0;
                for(auto node : parents){
                    currSum += ds.getComponentSize(node);
                }
                ans = max(ans,currSum+1);
            }
        }

        return ans;
    }
};