class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0;
        while(p2 < n){
            while(p2 < n && nums[p2] == nums[p1])
                p2++;
            if(p2 >= n) return p1+1;
            nums[p1+1] = nums[p2];
            p1++;
        }
        return p1+1;
    }
};