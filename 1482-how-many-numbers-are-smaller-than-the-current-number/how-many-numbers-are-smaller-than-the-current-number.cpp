class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>cnt(maxi+1,0);
        vector<int>ans(n);
        for(int i=0;i<n;i++)
            cnt[nums[i]]++;
        for(int i=1;i<=maxi;i++)
            cnt[i] += cnt[i-1];
        for(int i=0;i<n;i++){
            if(nums[i] == 0)
                ans[i] = 0;
            else
                ans[i] = cnt[nums[i] - 1];
        }
        return ans;
    }
};