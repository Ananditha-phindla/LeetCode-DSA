class Solution {
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i > j)   return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int mini = INT_MAX;

        for(int k=i;k<=j;k++){
            int curr = solve(i,k-1,cuts,dp) + solve(k+1,j,cuts,dp) + cuts[j+1] - cuts[i-1];
            mini = min(mini,curr);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int s = cuts.size();
        vector<vector<int>> dp(s,vector<int>(s,0));

        for(int i=s-2;i>=1;i--){
            for(int j=i;j<=s-2;j++){
                int mini = INT_MAX;
                for(int k=i;k<=j;k++){
                    int curr = dp[i][k-1] + dp[k+1][j] + cuts[j+1] - cuts[i-1];
                    mini = min(mini,curr);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][s-2];

        //return solve(1,s-2,cuts,dp);
    }
};