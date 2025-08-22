class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r < nums.size()-1){
            int maxDistance = 0;
            for(int i=l;i<=r;i++){
                maxDistance = max(maxDistance, i+nums[i]);
            }
            l = r+1;
            r = maxDistance;
            jumps++;
        }
        
        return jumps;
    }
};