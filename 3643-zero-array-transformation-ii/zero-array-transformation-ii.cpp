class Solution {
public:
    bool isvalid(vector<int>& nums, vector<vector<int>>& queries,int end){
        int n = nums.size();
        vector<int>pref(n,0);
        for(int i=0;i<=end;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            pref[l] += k;
            if(r+1 < n)
                pref[r+1] -= k;
        }
        for(int i=1;i<n;i++){
            pref[i] += pref[i-1];
        }
        for(int i=0;i<n;i++){
            if(pref[i] < nums[i])
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = -1;
        int low = 0;
        int high = queries.size()- 1;
        if(count(nums.begin(),nums.end(),0) == nums.size())
            return 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isvalid(nums,queries,mid)){
                ans = mid+1;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};