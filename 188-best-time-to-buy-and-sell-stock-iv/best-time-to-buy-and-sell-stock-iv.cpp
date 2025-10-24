class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2*k+1,0);

        for(int i=n-1;i>=0;i--){
            vector<int> curr(2*k+1,0);
            for(int j=2*k-1;j>=0;j--){
                if(j % 2 == 0){
                    int include = -prices[i] + next[j+1];
                    int skip = next[j];
                    curr[j] = max(include,skip);
                }
                else{
                    int include = prices[i] + next[j+1];
                    int skip = next[j];
                    curr[j] = max(include,skip);
                }
            }
            next = curr;
        }

        return next[0];
    }
};