class Solution {
public:
    void fillLeft(vector<int>& heights, vector<int>& left){
        stack<int> st;
        int n = heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty())
                left[i] = st.top();
            st.push(i);
        }
    }

    void fillRight(vector<int>& heights, vector<int>& right){
        stack<int> st;
        int n = heights.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty())
                right[i] = st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        
        fillLeft(heights,left);
        fillRight(heights,right);

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,((right[i]-left[i]-1) * heights[i]));
        }

        return ans;
    }
};