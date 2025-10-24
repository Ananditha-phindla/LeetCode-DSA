class Solution {
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx == prices.size())   return 0;
        if(dp[idx][buy] != -1)  return dp[idx][buy];

        if(buy == 1){
            int include = -prices[idx]+solve(idx+1,0,prices,dp);
            int skip = solve(idx+1,1,prices,dp);
            return dp[idx][buy] = max(include,skip); 
        }
        int include = prices[idx] + solve(idx+1,1,prices,dp);
        int skip = solve(idx+1,0,prices,dp);
        return dp[idx][buy] = max(include,skip); 

    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j == 0){
                    int include = prices[i] + dp[i+1][1];
                    int skip = dp[i+1][0];
                    dp[i][j] = max(include,skip);
                }
                else{
                    int include = -prices[i] + dp[i+1][0];
                    int skip = dp[i+1][1];
                    dp[i][j] = max(include,skip);
                }
            }
        }

        return dp[0][1];
        //return solve(0,1,prices,dp);
    }
};