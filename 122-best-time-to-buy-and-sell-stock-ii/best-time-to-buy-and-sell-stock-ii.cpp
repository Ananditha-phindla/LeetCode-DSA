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
        vector<int> next(2,0);

        for(int i=n-1;i>=0;i--){
            vector<int> curr(2,0);
            
            int include = prices[i] + next[1];
            int skip = next[0];
            curr[0] = max(include,skip);
            
            include = -prices[i] + next[0];
            skip = next[1];
            curr[1] = max(include,skip);

            next = curr;
        }

        return next[1];
        //return solve(0,1,prices,dp);
    }
};