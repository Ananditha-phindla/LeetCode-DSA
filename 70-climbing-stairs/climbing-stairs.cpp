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
        return memoi(dp,n);
    }
};