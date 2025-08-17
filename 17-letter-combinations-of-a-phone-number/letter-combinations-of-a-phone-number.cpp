class Solution {
public:
    void solve(string &digits,int idx,vector<string>&match,string curr,vector<string>&ans){
        if(idx == digits.length()){
            ans.push_back(curr);
            return;
        }
        int num = digits[idx] - '0';
        for(char c : match[num]){
            solve(digits,idx+1,match,curr+c,ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        vector<string> match(10);
        match[2] = "abc";
        match[3] = "def";
        match[4] = "ghi";
        match[5] = "jkl";
        match[6] = "mno";
        match[7] = "pqrs";
        match[8] = "tuv";
        match[9] = "wxyz";
        vector<string>ans;
        solve(digits,0,match,"",ans);
        return ans;
    }
};