class Solution {
    int solve(int i, int j, string word1, string word2, vector<vector<int>>& dp){
        if(i < 0)   return j+1;
        if(j < 0)   return i+1;
        if(dp[i][j] != -1)  return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i-1,j-1,word1,word2,dp);
        }
        return dp[i][j] = 1 + min({solve(i-1,j,word1,word2,dp),solve(i,j-1,word1,word2,dp),solve(i-1,j-1,word1,word2,dp)});
    }

public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++){
            dp[i][0] = i;
        }

        for(int i=0;i<=n2;i++){
            dp[0][i] = i;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }

        return dp[n1][n2];
        //return solve(n1-1,n2-1,word1,word2,dp);
    }
};