class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        vector<int> prev(n2+1,0);
        for(int i=1;i<=n1;i++){
            vector<int> curr(n2+1,0);
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }

        return n1+n2-2*prev[n2];
    }
};