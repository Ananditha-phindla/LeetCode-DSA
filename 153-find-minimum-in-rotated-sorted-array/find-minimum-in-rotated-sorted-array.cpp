class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = (low +(high-low)/2);
            if(nums[low] <= nums[mid]){
                mini = min(mini,nums[low]);
                low = mid + 1;
            }
            else{
                mini = min(mini,nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};