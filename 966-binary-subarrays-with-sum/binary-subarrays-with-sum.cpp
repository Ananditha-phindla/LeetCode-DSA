class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int ans = 0;
        int curr = 0;
        for(int i : nums){
            curr += i;
            if(mp.count(curr - goal)){
                ans += mp[curr-goal];
            }
            mp[curr]++;
        }
        if(mp.count(goal))
            ans += mp[goal];
        return ans;
    }
};