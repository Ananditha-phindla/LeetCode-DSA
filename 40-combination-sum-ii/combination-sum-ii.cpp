class Solution {
public:
    void solve(vector<int>& candidates, int target,int i,vector<int>curr,vector<vector<int>>&ans){
        if(target < 0)
            return;
        if(target == 0){
                ans.push_back(curr);
                return;
            }
        
        for(int j=i;j<candidates.size();j++){
            if(i == j || candidates[j] != candidates[j-1]){
                curr.push_back(candidates[j]);
                solve(candidates,target-candidates[j],j+1,curr,ans);
                curr.pop_back();
            }
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,{},ans);
        return ans;
    }
};