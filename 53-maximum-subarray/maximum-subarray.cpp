class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int prev = 0;
        for(int i=0;i<n;i++){
            prev = max(prev,0) + nums[i];
            ans = max(ans,prev);
        }
        return ans;
    }
};