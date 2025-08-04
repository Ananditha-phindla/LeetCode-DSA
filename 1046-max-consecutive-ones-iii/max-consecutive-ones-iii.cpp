class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int cnt = k;
        while(j < n){
            if(nums[j] == 0){
                if(cnt > 0){
                    cnt -= 1;
                }
                else{
                    while(i < j && nums[i] != 0)
                        i++;
                    i++;
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};