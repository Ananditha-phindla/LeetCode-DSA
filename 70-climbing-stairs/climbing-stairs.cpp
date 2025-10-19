class Solution {
public:
    int memoi(vector<int>& dp, int n){
        if(n <= 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = memoi(dp,n-1) + memoi(dp,n-2);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
        //return memoi(dp,n);
    }
};