class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i == n || heights[st.top()] > heights[i])){
                int h = heights[st.top()];
                st.pop();
                int l = (st.empty()) ? -1 : st.top();
                int r = i;
                int area = h * (r-l-1);
                ans = max(ans,area);
            }
            st.push(i);
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            ans = max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};