class Solution {
    int memoi(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i < 0 || j < 0) return INT_MAX;
        if(i == 0 && j == 0) return grid[i][j];
        if(dp[i][j] != -1)  return dp[i][j];

        //cout << grid[i][j] << " ";
        return dp[i][j] = grid[i][j] + min(memoi(i,j-1,grid,dp),memoi(i-1,j,grid,dp));
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return memoi(m-1,n-1,grid,dp);

    }
};