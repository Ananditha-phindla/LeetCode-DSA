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
        vector<int> prev(n2+1,0);

        for(int i=0;i<=n2;i++){
            prev[i] = i;
        }


        for(int i=1;i<=n1;i++){
            vector<int> curr(n2+1,0);
            curr[0] = i;
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else
                    curr[j] = 1 + min({prev[j],curr[j-1],prev[j-1]});
            }
            prev = curr;
        }

        return prev[n2];
        //return solve(n1-1,n2-1,word1,word2,dp);
    }
};