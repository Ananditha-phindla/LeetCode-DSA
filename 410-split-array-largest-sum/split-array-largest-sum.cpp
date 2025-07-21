class Solution {
public:
    bool isValid(vector<int>& nums, int k,int mid){
        int currsum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > mid)
                return false;
            if(currsum + nums[i] > mid){
                k--;
                currsum = nums[i];
            }
            else
                currsum += nums[i];
        }
        k--;
        return (k >= 0);
    }
    int splitArray(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);
        int ans = hi;
        while(lo <= hi){
            int mid = (lo + (hi-lo)/2);
            if(isValid(nums,k,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else 
                lo = mid + 1;
        }
        return ans;
    }
};