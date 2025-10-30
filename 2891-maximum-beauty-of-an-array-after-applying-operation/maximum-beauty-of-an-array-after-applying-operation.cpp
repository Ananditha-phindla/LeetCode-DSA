class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> mp;

        for(int i : nums){
            mp[i-k]++;
            mp[i+k+1]--;
        }

        int sum = 0;
        int maxi = 0;

        for(auto it : mp){
            int k = it.first;
            mp[k] += sum;
            sum = mp[k];
            maxi = max(maxi,sum);
        }

        return maxi;
    }
};