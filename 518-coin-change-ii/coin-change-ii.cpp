class Solution {
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(idx == 0)    return amount%coins[0] == 0;
        if(dp[idx][amount] != -1)   return dp[idx][amount];

        int take = 0;
        if(amount >= coins[idx])
            take = solve(idx,amount-coins[idx],coins,dp);
        int skip = solve(idx-1,amount,coins,dp);

        return dp[idx][amount] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
       vector<unsigned long long> prev(amount+1,0);

        for(int i=0;i<=amount;i++){
            prev[i] = (i%coins[0] == 0);
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                unsigned long long take = 0;
                if(j >= coins[i])
                    take = prev[j-coins[i]];
                unsigned long long skip = prev[j];
                prev[j] = take + skip;
            }
        }

        return prev[amount];
        //return solve(n-1,amount,coins,dp);
    }
};