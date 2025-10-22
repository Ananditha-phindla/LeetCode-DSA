class Solution {
    bool memoi(int i, int curr, int rest, vector<int>& nums, vector<vector<int>>& dp){
        if(curr == rest)  return true;
        if(i < 0 || curr > rest)  return false;
        if(dp[i][curr] != -1)  return dp[i][curr];

        return dp[i][curr] = memoi(i-1,curr+nums[i],rest-nums[i],nums,dp) || memoi(i-1,curr,rest,nums,dp);
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if(totalSum % 2)   return false;
        vector<vector<int>> dp(n,vector<int>(totalSum/2+1,0));

        if(nums[0] == totalSum/2)
            dp[0][totalSum/2] = 1;

        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=totalSum/2;j++){
                if(nums[i] <= j){
                    dp[i][j] = dp[i-1][j-nums[i]];
                }
                dp[i][j] |= dp[i-1][j];
            }
        }

        return dp[n-1][totalSum/2];
        return memoi(n-1,0,totalSum,nums,dp);

    }
};