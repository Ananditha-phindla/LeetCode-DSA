class Solution {
public:
    void solve(int k,int n,int currSum,vector<int> curr,vector<vector<int>>&ans,int i){
        if(curr.size() == k){
            if(currSum == n){
                ans.push_back(curr);
            }
            return;
        }
        if(i > 9)
            return;
        solve(k,n,currSum,curr,ans,i+1);
        curr.push_back(i);
        solve(k,n,currSum+i,curr,ans,i+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        vector<vector<int>>ans;
        solve(k,n,0,curr,ans,1);
        return ans;
    }
};