class Solution {
public:
    void findNGE(vector<int>& nge,vector<int>& nums){
        stack<int>st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if(st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();
            st.push(i);
        }
    }

    void findNSE(vector<int>& nse,vector<int>& nums){
        stack<int>st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();
            st.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        int m = 1e9+7;
        vector<int>nge(n);
        findNGE(nge,nums);
        vector<int>nse(n);
        findNSE(nse,nums);
        long long max_sum = 0;
        long long min_sum = 0;
        stack<int>pse;
        stack<int>pge;
        for(int i=0;i<n;i++){
            int lse,lge;
            while(!pge.empty() && nums[pge.top()] < nums[i])
                pge.pop();
            if(pge.empty())
                lge = -1;
            else
                lge = pge.top();
            pge.push(i);

            while(!pse.empty() && nums[pse.top()] > nums[i])
                pse.pop();
            if(pse.empty())
                lse = -1;
            else
                lse = pse.top();
            pse.push(i);
            int l = i - lse;
            int r = nse[i] - i;
            cout << lse << lge << nse[i] << nge[i] << endl;
            min_sum = (min_sum + (l * r *1LL)*nums[i]);
            l = i - lge;
            r = nge[i] - i;
            max_sum = (max_sum + (l * r*1LL)*nums[i]);

        }
        return max_sum - min_sum;
    }
};