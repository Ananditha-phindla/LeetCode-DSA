class Solution {
    int memoi(int idx, int amount,vector<int>& coins,  vector<vector<int>> &dp){
        if(idx < 0 || amount < 0) return -1;
        if(amount == 0) return dp[idx][0] = 0;
        if(dp[idx][amount] != -1)   return dp[idx][amount];

        int take = -1;
        if(amount >= coins[idx])
            take = 1 + memoi(idx,amount-coins[idx],coins,dp);
        int skip = memoi(idx-1,amount,coins,dp);
        if(take > 0 && skip > 0)
            return dp[idx][amount] = min(take,skip);
        else if(skip > 0)
            return dp[idx][amount] = skip;
        else if(take > 0) 
            return dp[idx][amount] = take;
        return dp[idx][amount] = -2;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        memoi(n-1,amount,coins,dp);
        if(dp[n-1][amount] == -2)
            return -1;
        return dp[n-1][amount];
    }
};