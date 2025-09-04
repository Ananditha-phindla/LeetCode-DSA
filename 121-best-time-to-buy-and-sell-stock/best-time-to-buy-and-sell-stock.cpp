class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int n = prices.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(buy > prices[i])
                buy = prices[i];
            else
                ans = max(ans,prices[i] - buy);
        }
        return ans;
    }
};