class Solution {
public:
    bool solve(vector<int>& nums, int idx, vector<int>& dp){
        if(idx == nums.size()-1)
            return true;
        if(idx >= nums.size())
            return false;
        if(dp[idx] != -1)
            return dp[idx];
        for(int i=nums[idx];i>0;i--){
            if(solve(nums,idx+i,dp))
                return dp[i] = true;
        }
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};