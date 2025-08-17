class Solution {
public:
    void solve(vector<int>& c, int target,int i,vector<int>curr,vector<vector<int>>&ans){
        if(target < 0)
            return;
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<c.size();j++){
            curr.push_back(c[j]);
            solve(c,target-c[j],j,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        solve(candidates,target,0,{},ans);
        return ans;
    }
};