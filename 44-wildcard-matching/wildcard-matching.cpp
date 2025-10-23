class Solution {
    bool allStars(int i, string s){
        while(i >= 0 && s[i] == '*')
            i--;
        
        return (i < 0);
    }

    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>& dp){
        if(i < 0 && j < 0)   return true;
        if(i < 0)   return false;
        if(j < 0){
            return allStars(i,s1);
        }
        if(dp[i][j] != -1)  return dp[i][j];

        if(s1[i] == s2[j] || s1[i] == '?')
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        else if(s1[i] == '*')
            return dp[i][j] = solve(i,j-1,s1,s2,dp) || solve(i-1,j,s1,s2,dp);
        else
            return false;
    }
public:
    bool isMatch(string s2, string s1) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> prev(n2+1,0);
        prev[0] = 1;

        for(int i=1;i<=n1;i++){
            vector<int> curr(n2+1,0);
            if(allStars(i-1,s1))
                curr[0] = 1;
            for(int j=1;j<=n2;j++){
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
                    curr[j] = prev[j-1];
                else if(s1[i-1] == '*')
                    curr[j] = curr[j-1] || prev[j];
            }
            prev = curr;
        }
        return prev[n2];
        //return solve(n1-1,n2-1,s1,s2,dp);
    }
};