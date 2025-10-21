class Solution {
    int memoi(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        cout <<i << " " <<j <<endl;
        if(i < 0 || j < 0 || obstacleGrid[i][j])  return 0;
        if(i == 0 && j == 0)   return 1;
        if(dp[i][j] != -1)  return dp[i][j];

        return dp[i][j] = memoi(i,j-1,obstacleGrid,dp) + memoi(i-1,j,obstacleGrid,dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return memoi(m-1,n-1,obstacleGrid,dp);
    }
};