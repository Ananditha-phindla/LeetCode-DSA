class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int nextBuy = 0;
        int nextNotBuy = 0;
        int currBuy, currNotBuy;

        for(int i=n-1;i>=0;i--){
            currBuy = max(-prices[i]+nextNotBuy,nextBuy);
            currNotBuy = max(prices[i]-fee+nextBuy,nextNotBuy);

            nextBuy = currBuy;
            nextNotBuy = currNotBuy;
        }

        return nextBuy;
    }
};