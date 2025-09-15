class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int st = 0;
        int n = s.length();
        int op = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(')
                op++;
            else
                op--;
            if(op == 0){
                ans += s.substr(st+1,i-st-1);
                st = i+1;
            }
        }
        return ans;
    }
};