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
        vector<vector<int>> dp(n,vector<int>(total+1,0));

        if(nums[0] == 0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
        }
        if(nums[0] != 0 && nums[0] <= total)
            dp[0][nums[0]] = 1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=total;j++){
                if(nums[i] <= j){
                    dp[i][j] = dp[i-1][j-nums[i]];
                }
                dp[i][j] += dp[i-1][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<=total;j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        int ways = 0;
        for(int i=0;i<=total/2;i++){
            int sum1 = i;
            int sum2 = total-i;
            if(abs(sum1-sum2) == abs(target)){
                ways += dp[n-1][i];
            }
        }

        return ways;

        //return memoi(n-1,0,target,total,nums,dp);
    }
};