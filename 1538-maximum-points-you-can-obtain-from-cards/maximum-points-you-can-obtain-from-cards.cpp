class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int p1 = 0;
        int p2 = n-1;
        int currSum = 0;
        int ans = 0;
        while(p1 < k){
            currSum += cardPoints[p1];
            p1++;
        }
        p1--;
        ans = currSum;
        while(p1 >= 0){
            currSum -= cardPoints[p1];
            currSum += cardPoints[p2];
            ans = max(ans,currSum);
            p1--;
            p2--;
        }
        return ans;
    }
};