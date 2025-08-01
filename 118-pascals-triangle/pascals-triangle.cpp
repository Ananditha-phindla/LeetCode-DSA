class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
            return {{1}};
        vector<vector<int>>ans;
        ans.push_back({{1}});
        for(int i=2;i<=numRows;i++){
            vector<int>curr(i);
            curr[0] = curr[i-1] = 1;
            for(int j=0;j<ans.back().size()-1;j++){
                curr[j+1] = ans.back()[j] + ans.back()[j+1];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};