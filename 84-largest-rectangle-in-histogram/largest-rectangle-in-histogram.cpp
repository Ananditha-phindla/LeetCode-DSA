class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        stack<int>st;
        vector<int>leftMin(n);
        vector<int>rightMin(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                leftMin[i] = -1;
            else
                leftMin[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                rightMin[i] = n;
            else
                rightMin[i] = st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            ans = max(ans,heights[i]*(rightMin[i]-leftMin[i]-1));
        }
        return ans;
    }
};