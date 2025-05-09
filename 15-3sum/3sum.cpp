class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            int p1 = i+1;
            int p2 = n-1;
            while(p1 < p2){
                if(p1 != i+1 && nums[p1] == nums[p1-1]){
                    p1++;
                    continue;
                }
                if(p2 != n-1 && nums[p2] == nums[p2+1]){
                    p2--;
                    continue;
                }
                if(nums[i]+nums[p1]+nums[p2] == 0){
                    ans.push_back({nums[i],nums[p1],nums[p2]});
                    p1++;
                    p2--;
                }
                else if(nums[i]+nums[p1]+nums[p2] > 0){
                    p2--;
                }
                else
                    p1++;
            }
        }
        return ans;
    }
};