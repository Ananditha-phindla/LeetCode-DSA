class Solution {
public:
    void solve(vector<int>& c, int target,int i,vector<int>curr,vector<vector<int>>&ans){
        if(target < 0)
            return;
        if(i == c.size()){
            if(target == 0)
                ans.push_back(curr);
            return;
        }
        solve(c,target,i+1,curr,ans);
        curr.push_back(c[i]);
        solve(c,target-c[i],i,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        solve(candidates,target,0,{},ans);
        return ans;
    }
};