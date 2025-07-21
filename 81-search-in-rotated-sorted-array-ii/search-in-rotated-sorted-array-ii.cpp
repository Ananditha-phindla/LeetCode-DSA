class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                lo++;
                hi--;
            }
            else if(nums[mid] <= nums[hi]){
                if(nums[mid] < target && nums[hi] >= target){
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }
            else if(nums[mid] >= nums[lo]){
                if(nums[lo] <= target && nums[mid] > target){
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }
        }
        return false;
    }
};