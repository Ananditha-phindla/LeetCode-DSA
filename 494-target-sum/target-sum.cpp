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
        if(target < -total || target > total)
            return 0;
        vector<vector<int>> dp(n,vector<int>(2*total+1,0));
        if(nums[0] == 0)
            dp[0][total] = 2;
        else {
            dp[0][nums[0]+total] = 1;
            dp[0][-nums[0]+total] = 1;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=2*total;j++){
                if(nums[i] <= j)
                    dp[i][j] += dp[i-1][j-nums[i]];
                if(j + nums[i] <= 2*total)
                    dp[i][j] +=  dp[i-1][j+nums[i]];
            }
        }

        return dp[n-1][target+total];

        //return memoi(n-1,0,target,total,nums,dp);
    }
};