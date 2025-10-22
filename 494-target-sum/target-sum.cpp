class Solution {
    int memoi(int idx, int curr, int target, int total, vector<int>& nums,vector<vector<int>>& dp){
        if(idx < 0) return (curr == target);
        if(dp[idx][curr+total] != -1)   return dp[idx][curr+total];

        int pos = memoi(idx-1,curr+nums[idx],target,total,nums,dp);
        int neg = memoi(idx-1,curr-nums[idx],target,total,nums,dp);

        return dp[idx][curr+total] = pos + neg;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int>(2*total+1,-1));

        return memoi(n-1,0,target,total,nums,dp);
    }
};