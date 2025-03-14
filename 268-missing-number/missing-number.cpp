class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>myset(nums.begin(),nums.end());
        for(int i=0;i<=n;i++){
            if(!myset.count(i))
                return i;
        }
        return 0;
    }
};