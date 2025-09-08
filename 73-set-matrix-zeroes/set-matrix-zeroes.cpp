class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto r : row){
            for(int i=0;i<m;i++){
                matrix[r][i] = 0;
            }
        }

        for(auto c : col){
            for(int i=0;i<n;i++){
                matrix[i][c] = 0;
            }
        }
    }
};