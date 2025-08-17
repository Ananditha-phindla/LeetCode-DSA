class Solution {
public:
    void solve(vector<int>& nums,int i,vector<int>&curr,vector<vector<int>>&ans){
        ans.push_back(curr);
        if(i == nums.size()){
            return;
        }

        for(int idx=i;idx<nums.size();idx++){
            if(i != idx && nums[idx] == nums[idx-1])
                continue;
            curr.push_back(nums[idx]);
            solve(nums,idx+1,curr,ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        solve(nums,0,curr,ans);
        return ans;
    }
};