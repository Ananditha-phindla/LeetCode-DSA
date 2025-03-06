class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>cnt(n*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cnt[grid[i][j] - 1]++;
            }
        }
        int a,b;
        for(int i=0;i<cnt.size();i++){
            if(cnt[i] == 2)
                a = i+1;
            if(cnt[i] == 0)
                b = i+1;
        }
        return {a,b};
    }
};