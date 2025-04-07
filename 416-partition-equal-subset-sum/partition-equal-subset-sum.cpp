class Solution {
public:
    bool solve(vector<int>& nums,int i,int sum,int currsum,vector<vector<int>>&dp){
        if(currsum == sum)
            return true;
        if(i < 0 || sum < 0)
            return false;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = (solve(nums,i-1,sum,currsum,dp) || solve(nums,i-1,sum-nums[i],currsum+nums[i],dp));
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(nums,n-1,sum,0,dp);
    }
};