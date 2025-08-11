class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i= 0;
        int j = 0;
        int prev = 0;
        unordered_map<int,int>mp;
        while(j < n){
            mp[nums[j]]++;
            while(i < j && (mp.size() > k || mp[nums[i]] > 1)){
                if(mp[nums[i]] > 1){
                    mp[nums[i]]--;
                    prev++;
                }
                else{
                    prev = 0;
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(mp.size() == k)
                ans += (prev + 1);
            j++;
        }
        return ans;
    }
};