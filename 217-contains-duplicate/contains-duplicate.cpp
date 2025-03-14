class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>myset;
        for(int i : nums){
            if(myset.count(i))
                return true;
            myset.insert(i);
        }
        return false;
    }
};