class Solution {
public:
    long long solve(vector<vector<int>>& q,int i,vector<long long>&dp){
        if(i  >= q.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(solve(q,i+1,dp),q[i][0] + solve(q,i + q[i][1] +1,dp));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,-1);
        return solve(questions,0,dp);
    }
};