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
       vector<int> prev(totalSum/2+1,0);

        prev[0] = 1;

        if(nums[0] <= totalSum/2)
            prev[nums[0]] = 1;

        for(int i=1;i<n;i++){
            vector<int> curr(totalSum/2+1,0);
            curr[0] = 1;
            for(int j=1;j<=totalSum/2;j++){
                if(nums[i] <= j){
                    curr[j] = prev[j-nums[i]];
                }
                curr[j] |= prev[j];
            }
            prev = curr;
        }

        return prev[totalSum/2];
        //return memoi(n-1,0,totalSum,nums,dp);

    }
};