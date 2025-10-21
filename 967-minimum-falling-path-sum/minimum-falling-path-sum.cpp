class Solution {
    int memoi(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix.size())  return INT_MAX;
        if(i == 0)  return matrix[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        return dp[i][j] = matrix[i][j] + min({memoi(i-1,j+1,matrix,dp),memoi(i-1,j,matrix,dp),memoi(i-1,j-1,matrix,dp)});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            ans = min(ans,memoi(n-1,i,matrix,dp));
        }
        return ans;
    }
};