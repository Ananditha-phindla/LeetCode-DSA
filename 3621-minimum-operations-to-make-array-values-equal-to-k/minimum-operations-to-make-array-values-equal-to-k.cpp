class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool>cnt(101,false);
        for(int num : nums){
            cnt[num] = true;
        }
        int i = k-1;
        while( i >= 0){
            if(cnt[i])
                return -1;
            i--;
        }
         i = k+1;
        int ans = 0;
        while(i < 101){
            if(cnt[i])
                ans++;
            i++;
        }
        return ans;
    }
};