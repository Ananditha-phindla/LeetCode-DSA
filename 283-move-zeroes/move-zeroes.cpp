class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0;
        while(p2 < n){
            while(p1 < n && nums[p1] != 0)
                p1++;
            while(p2 < n && nums[p2] == 0)
                p2++;
            if(p1 < n && p2 < n && p2 > p1){
                swap(nums[p1],nums[p2]);
                p1++;
            }
            p2++;
        }
        return;
    }
};