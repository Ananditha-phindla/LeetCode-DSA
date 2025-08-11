class Solution {
public:
    void fillPowers(int n, vector<int>&powers){
        int i=0;
        while(n > 0){
            if(n & 1){
                powers.push_back(1<<i);
            }
            i++;
            n = n >> 1;
        }
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int m = 1e9+7;
        vector<int>powers;
        fillPowers(n,powers);
        vector<int>ans;
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            long curr = 1;
            for(int i=l;i<=r;i++){
                curr = (curr * powers[i])%m;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};