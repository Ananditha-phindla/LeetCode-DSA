class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        if(n == 1)
            return nums[0];
        while(lo <= hi){
            int mid = (lo + (hi - lo)/2);
            if(mid % 2 == 0){
                if(mid+1 < n && nums[mid] == nums[mid+1]){
                    lo = mid + 1;
                }
                else if(mid-1 >= 0 && nums[mid] == nums[mid-1])
                    hi = mid - 1;
                else
                    return nums[mid];
            }
            else{
                if(mid-1 >= 0 && nums[mid] == nums[mid-1])
                    lo = mid + 1;
                else if(mid+1 < n && nums[mid] == nums[mid+1])
                    hi = mid - 1;
                else
                    return nums[mid];
            }
        }
        return 0;
    }
};