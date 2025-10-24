class Solution {
    bool static comp(string &a, string &b){
        return a.length() < b.length();
    }

    bool isValid(string &s1, string &s2){
        if(s2.length()-s1.length() > 1 || s2.length()-s1.length() == 0) return false;
        int i = 0, j = 0;

        while(i < s1.length() && j < s2.length()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else
                j++;
        }

        return i == s1.length();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int ans = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isValid(words[j],words[i]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    ans = max(ans,dp[i]);
                    cout << words[j] << " ";
                }
            }
        }

        return ans;
    }
};