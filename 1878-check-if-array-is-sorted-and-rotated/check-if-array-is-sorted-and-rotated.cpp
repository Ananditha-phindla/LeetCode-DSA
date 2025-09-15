class Solution {
public:
    bool check(vector<int>& nums) {
        int dec = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1])
                dec++;
        }
        return (dec == 0 || (dec <= 1 && nums[0] >= nums[n-1]));
    }
};