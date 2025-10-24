class Solution {
    int solve(int i, int t, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size() || t == 4)   return 0;
        if(dp[i][t] != -1)  return dp[i][t];

        if(t % 2 == 0){
            int include = -prices[i] + solve(i+1,t+1,prices,dp);
            int skip = solve(i+1,t,prices,dp);
            return dp[i][t] = max(include,skip);
        }

        int include = prices[i] + solve(i+1,t+1,prices,dp);
        int skip = solve(i+1,t,prices,dp);
        return dp[i][t] = max(include,skip);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));

        for(int i=n-1;i>=0;i--){
            for(int j=3;j>=0;j--){
                if(j % 2 == 0){
                    int include = -prices[i] + dp[i+1][j+1];
                    int skip = dp[i+1][j];
                    dp[i][j] = max(include,skip);
                }
                else{
                    int include = prices[i] + dp[i+1][j+1];
                    int skip = dp[i+1][j];
                    dp[i][j] = max(include,skip);
                }
            }
        }
        return dp[0][0];
        //return solve(0,0,prices,dp);
    }
};