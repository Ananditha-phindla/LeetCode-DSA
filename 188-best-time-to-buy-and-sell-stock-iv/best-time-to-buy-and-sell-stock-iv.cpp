class Solution {
    int solve(int i, int buy, int k,int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(k == cap || i == prices.size())   return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        if(buy == 1){
            int include = -prices[i] + solve(i+1,0,k,cap,prices,dp);
            int skip = solve(i+1,1,k,cap,prices,dp);
            return dp[i][buy][k] = max(include,skip);
        }
        int include = prices[i] + solve(i+1,1,k+1,cap,prices,dp);
        int skip = solve(i+1,0,k,cap,prices,dp);
        return dp[i][buy][k] = max(include,skip);
    }

public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k,-1)));

        
        return solve(0,1,0,k,prices,dp);
    }
};