class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int nums_xor = 0;
        int total_xor = 0;
        for(int i=0;i<n;i++){
            nums_xor ^= nums[i];
            total_xor ^= i+1;
        }
        return total_xor ^ nums_xor;
    }
};