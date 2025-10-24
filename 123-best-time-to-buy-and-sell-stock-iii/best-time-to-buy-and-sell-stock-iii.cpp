class Solution {
    int solve(int i, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(k == 2 || i == prices.size())   return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        if(buy == 1){
            int include = -prices[i] + solve(i+1,0,k,prices,dp);
            int skip = solve(i+1,1,k,prices,dp);
            return dp[i][buy][k] = max(include,skip);
        }
        int include = prices[i] + solve(i+1,1,k+1,prices,dp);
        int skip = solve(i+1,0,k,prices,dp);
        return dp[i][buy][k] = max(include,skip);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n+1,vector<vector<long>>(2,vector<long>(3,0)));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k>=0;k--){
                    if(j == 0){
                        long include = prices[i] + dp[i+1][1][k+1];
                        long skip = dp[i+1][0][k];
                        dp[i][j][k] = max(include,skip);
                    }
                    else{
                        long include = -prices[i] + dp[i+1][0][k];
                        long skip = dp[i+1][1][k];
                        dp[i][j][k] = max(include,skip);
                    }
                }
            }
        }

        return dp[0][1][0];
        //return solve(0,1,0,prices,dp);
    }
};