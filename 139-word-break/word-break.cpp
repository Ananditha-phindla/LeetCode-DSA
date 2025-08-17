class Solution {
public:
    bool solve(string s,unordered_set<string>&myset,int idx,vector<int>&dp){
        if(idx == s.length()){
            return true;
        }
        if(dp[idx] != -1)
            return dp[idx];
        string curr = "";
        for(int i=idx; i<s.length(); i++){
            curr += s[i];
            if(myset.count(curr) && solve(s,myset,i+1,dp)){
                return dp[i] = true;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>myset(wordDict.begin(),wordDict.end());
        vector<int>dp(s.length(),-1);
        return solve(s,myset,0,dp);
    }
};