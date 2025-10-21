class Solution {
    int memoi(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp){
        if(i >= grid.size() || j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())   return 0;
        if(i == grid.size()-1){
            if(j1 == j2)   return grid[i][j2];
            else    return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = 0;

        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ans;

                if (j1 == j2)
                    ans = grid[i][j1] + memoi(i + 1, j1 + di, j2 + dj, grid, dp);
                else
                    ans = grid[i][j1] + grid[i][j2] + memoi(i + 1, j1 + di, j2 + dj,grid, dp);
                
                maxi = max(maxi, ans);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

        return memoi(0,0,m-1,grid,dp);
    }
};