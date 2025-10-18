class Solution {
    typedef pair<int,pair<int,int>> P;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<bool>> vis(n,vector<bool>(n,false));

        pq.push({grid[0][0],{0,0}});
        vis[0][0] = true;

        while(!pq.empty()){
            int dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i == n-1 && j == n-1)
                return dist;
            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj]){
                    int curr = max(dist,grid[ni][nj]);
                    pq.push({curr,{ni,nj}});
                    vis[ni][nj] = true;
                }
            }
        }
        return -1;
    }
};