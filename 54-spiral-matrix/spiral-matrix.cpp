class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, down = n-1;
        int left = 0, right = m-1;
        while(top <= down && left <= right){
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;
            for(int i=top;i<=down;i++)
                ans.push_back(matrix[i][right]);
            right--;
            if(down >= top){
                for(int i=right;i>=left;i--)
                    ans.push_back(matrix[down][i]);
                down--;
            }
            if(left <= right){
                for(int i=down;i>=top;i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};