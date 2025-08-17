class Solution {
public:
    bool isPalindrome(string s){
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    void solve(string s,int idx, vector<string>&curr,vector<vector<string>>&ans){
        if(idx == s.length()){
            ans.push_back(curr);
            return;
        }
        string c = "";
        for(int i=idx;i<s.length();i++){
            c += s[i];
            if(isPalindrome(c)){
                curr.push_back(c);
                solve(s,i+1,curr,ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>curr;
        vector<vector<string>>ans;
        solve(s,0,curr,ans);
        return ans;
    }
};