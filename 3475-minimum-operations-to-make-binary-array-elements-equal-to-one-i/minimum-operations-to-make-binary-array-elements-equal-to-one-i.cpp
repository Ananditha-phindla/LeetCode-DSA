class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i] == 0){
                nums[i] = 1;
                if(nums[i+1] == 0)
                    nums[i+1] = 1;
                else
                     nums[i+1]= 0;
                if(nums[i+2] == 0)
                    nums[i+2] = 1;
                else
                     nums[i+2] = 0;
                cnt++;
            }
        }
        if(nums[n-2] == 0 || nums[n-1] == 0){
            return -1;
        }
        return cnt;
    }
    
        
};