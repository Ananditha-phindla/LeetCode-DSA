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
        int nextNotBuy = 0;
        int nextBuy = 0;
        int currNotBuy = 0;
        int currBuy = 0;

        for(int i=n-1;i>=0;i--){
            currNotBuy = max(prices[i] + nextBuy,nextNotBuy);
            currBuy = max(-prices[i] + nextNotBuy,nextBuy);

            nextBuy = currBuy;
            nextNotBuy = currNotBuy;
        }

        return nextBuy;
        //return solve(0,1,prices,dp);
    }
};