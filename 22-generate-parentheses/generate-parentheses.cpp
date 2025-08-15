class Solution {
public:
    void solve(int n,string curr,int openCnt,int closeCnt,vector<string>&ans){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(openCnt < n){
            solve(n,curr+"(",openCnt+1,closeCnt,ans);
        }
        if(closeCnt < openCnt){
            solve(n,curr+")",openCnt,closeCnt+1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,"",0,0,ans);
        return ans;
    }
};