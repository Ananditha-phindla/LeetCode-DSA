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
        vector<int> dp(n,-1);

        return memoi(nums,dp,n-1);
    }
};