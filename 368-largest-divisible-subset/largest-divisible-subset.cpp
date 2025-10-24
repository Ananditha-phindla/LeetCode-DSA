class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n,1);
        vector<int> parent(n,0);
        for(int i=1;i<n;i++)
            parent[i] = i;

        int maxi = 1;
        int idx = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    if(dp[i] > maxi){
                        maxi = dp[i];
                        idx = i;
                    }
                    parent[i] = j;
                } 
            }
        }

        vector<int> ans(maxi);
        int l = maxi - 1;

        while(parent[idx] != idx){
            ans[l] = nums[idx];
            idx = parent[idx];
            l--;
        }
        ans[0] = nums[idx];

        return ans;

    }
};