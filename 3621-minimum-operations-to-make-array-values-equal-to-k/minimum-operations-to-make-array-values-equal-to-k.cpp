class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>myset;
        for(auto n : nums){
            if(n < k)
                return -1;
            if(n > k)
                myset.insert(n);
        }
        return myset.size();
    }
};