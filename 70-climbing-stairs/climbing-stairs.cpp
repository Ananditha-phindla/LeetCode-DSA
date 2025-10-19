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
        //vector<int> dp(n+1,-1);
        int prev1,prev2;
        prev1 = prev2 = 1;
        int curr;
        for(int i=2;i<=n;i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        //return memoi(dp,n);
    }
};