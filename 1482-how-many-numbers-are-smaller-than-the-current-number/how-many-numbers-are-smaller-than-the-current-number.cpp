class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>cnt(maxi+1,0);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            cnt[nums[i]]++;
        }
        int c = 0;
        for(int i=0;i<=maxi;i++){
            if(cnt[i] != 0){
                for(int j : mp[i])
                    ans[j] = c;
                c += cnt[i];
            }
        }
        return ans;
    }
};