class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);

        for(auto b : bookings){
            int f = b[0] - 1;
            int l = b[1] - 1;
            int s = b[2];

            ans[f] += s;
            if(l + 1 < n)
                ans[l+1] -= s;
        }

        for(int i=1;i<n;i++){
            ans[i] += ans[i-1];
        }

        return ans;
    }
};