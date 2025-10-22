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
        vector<vector<int>> dp(n,vector<int>((totalSum+1)/2,-1));

        return memoi(n-1,0,totalSum,nums,dp);

    }
};