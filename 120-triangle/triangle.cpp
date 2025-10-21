class Solution {
    int memoi(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= triangle.size() || j >= triangle[i].size())  return INT_MAX;
        if(i == 0)  return triangle[0][0];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(memoi(i-1,j,triangle,dp),memoi(i-1,j-1,triangle,dp));
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        int ans = INT_MAX;

        for(int i=0;i<m;i++){
            ans = min(ans,memoi(m-1,i,triangle,dp));
            cout << ans << " ";
        }

        return ans;
    }
};