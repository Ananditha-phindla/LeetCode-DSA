class Solution {
public:
    void findNSE(vector<int>& arr,vector<int>& nse){
        int n = arr.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        vector<int>nse(n);
        findNSE(arr,nse);
        long long sum = 0;
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            int pse = (st.empty()) ? pse = -1 :  st.top();
            st.push(i);
            long long cnt = 0;
            long long l = (i-pse);
            long long r = nse[i] - i;
            cnt = (r*l)*arr[i];
            sum = (sum + cnt)%mod;
        }
        return sum;
    }
};