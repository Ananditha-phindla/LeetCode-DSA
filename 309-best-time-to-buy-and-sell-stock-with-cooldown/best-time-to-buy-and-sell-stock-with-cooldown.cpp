class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>next1 (2,0);
        vector<int>next2 (2,0);

        for(int i=n-1;i>=0;i--){
            vector<int> curr(2,0);

            curr[0] = max(prices[i] + next2[1],next1[0]);

            curr[1] = max(-prices[i]+next1[0],next1[1]);

            next2 = next1;
            next1 = curr;
        }
        return next1[1];
    }
};