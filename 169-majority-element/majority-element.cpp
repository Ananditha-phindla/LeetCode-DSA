class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int maj;
        for(int i=0;i<nums.size();i++){
            if(cnt == 0){
                maj = nums[i];
                cnt = 1;
            }
            else if(nums[i] == maj)
                cnt++;
            else
                cnt--;
        }
        return maj;
    }
};