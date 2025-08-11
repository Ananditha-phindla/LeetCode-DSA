class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int prev_zeroes = 0;
        int ans = 0;
        int currSum = 0;
        int i = 0;
        int j = 0;
        while(j < n){
            currSum += nums[j];
            while(i < j && (nums[i] == 0 || currSum > goal)){
                if(nums[i] == 0)
                    prev_zeroes++;
                else{
                    prev_zeroes = 0;
                    currSum -= 1;
                }
                i++;
            }
            if(currSum == goal)
                ans += (prev_zeroes + 1);
            j++;
        }
        return ans;
    }
};