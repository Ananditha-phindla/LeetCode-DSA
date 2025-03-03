class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> greater;
        vector<int> smaller;
        vector<int> ans;
        int equal = 0;
        for(auto i : nums){
            if(i == pivot)
                equal++;
            else if(i > pivot)
                greater.push_back(i);
            else
                smaller.push_back(i);
        }
        for(auto i : smaller)
            ans.push_back(i);
        while(equal--)
            ans.push_back(pivot);
        for(auto i : greater)
            ans.push_back(i);
        return ans;
    }
};