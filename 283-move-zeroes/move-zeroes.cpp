class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int idx = 0;
        while(i < n){
            if(nums[i] != 0)
                nums[idx++] = nums[i];
            i++;
        }

        while(idx < n)
            nums[idx++] = 0;
    }
};