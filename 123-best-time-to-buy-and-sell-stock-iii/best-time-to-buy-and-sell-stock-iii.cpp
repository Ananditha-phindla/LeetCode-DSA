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
        vector<int> next(5,0);

        for(int i=n-1;i>=0;i--){
            vector<int> curr(5,0);
            for(int j=3;j>=0;j--){
                if(j % 2 == 0){
                    int include = -prices[i] + next[j+1];
                    int skip = next[j];
                    curr[j] = max(include,skip);
                }
                else{
                    int include = prices[i] + next[j+1];
                    int skip = next[j];
                    curr[j] = max(include,skip);
                }
            }
            next = curr;
        }
        return next[0];
        //return solve(0,0,prices,dp);
    }
};