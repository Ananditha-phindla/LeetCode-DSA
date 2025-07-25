class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            bool isEqual = false;
            while(!st.empty() && (asteroids[i] < 0 && st.top() > 0)){
                int curr = abs(asteroids[i]);
                int top_val = abs(st.top());
                if(curr == top_val){
                    st.pop();
                    isEqual = true;
                    break;
                }
                else if(curr < top_val){
                    isEqual = true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!isEqual)
                st.push(asteroids[i]);
        }
        if(st.empty())
            return {};
        int ans_len = st.size();
        vector<int>ans(ans_len);
        for(int i=ans_len-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;

    }
};