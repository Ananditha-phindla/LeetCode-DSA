class Solution {
public:
    void solve(int n,vector<int>curr,int i,vector<vector<int>>&ans,vector<int>& nums){
        if(i == n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(n,curr,i+1,ans,nums);
        curr.pop_back();
        solve(n,curr,i+1,ans,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        solve(n,{},0,ans,nums);
        return ans;
    }
};