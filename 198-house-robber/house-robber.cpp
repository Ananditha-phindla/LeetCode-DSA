class Solution {
public:
    int memoi(vector<int> &nums, vector<int> &dp, int n){
        if(n < 0) return 0;
        if(n == 0) return nums[0];
        if(dp[n] != -1)  return dp[n];

        int include = nums[n] + memoi(nums,dp,n-2);
        int skip = memoi(nums,dp,n-1);
        return dp[n] = max(include,skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int include = nums[i] + dp[i-2];
            int exclude = dp[i-1];
            dp[i] = max(include,exclude);
        }
        return dp[n-1];
        return memoi(nums,dp,n-1);
    }
};