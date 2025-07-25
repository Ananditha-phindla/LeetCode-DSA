class Solution {
public:
    void findNGE(vector<int>& nums, vector<int>& nge){
        stack<int>st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i])
                st.pop();
            if(st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();
            st.push(nums[i]);
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>nge(n);
        findNGE(nums2,nge);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]] = i;
        }
        int m = nums1.size();
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            ans[i] = nge[mp[nums1[i]]];
        }
        return ans;
    }
};