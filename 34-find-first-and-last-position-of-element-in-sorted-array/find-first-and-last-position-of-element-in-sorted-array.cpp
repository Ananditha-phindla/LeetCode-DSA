class Solution {
public:
    int findFirstOcc(vector<int> &nums, int target){
        int lo = 0;
        int hi = nums.size() - 1;
        int first = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                first = mid;
                hi = mid - 1;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else 
                hi = mid - 1;
        }
        return first;
    }
    int findLastOcc(vector<int> &nums, int target){
        int lo = 0;
        int hi = nums.size() - 1;
        int last = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                last = mid;
                lo = mid + 1;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else 
                hi = mid - 1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1,-1};
        }
        vector<int>ans(2);
        ans[0] = findFirstOcc(nums,target);
        if(ans[0] == -1){
            return {-1,-1};
        }
        ans[1] = findLastOcc(nums,target);
        return ans;
    }
};