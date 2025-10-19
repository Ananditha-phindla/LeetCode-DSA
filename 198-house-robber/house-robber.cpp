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
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int include = nums[i] + prev2;
            int exclude = prev1;
            int curr = max(include,exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
       // return memoi(nums,dp,n-1);
    }
};