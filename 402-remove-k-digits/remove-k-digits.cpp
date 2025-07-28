class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k == n)
            return "0";
        stack<char>st;
        for(int i=0;i<n;i++){
           while(k > 0 && (!st.empty() && st.top() > num[i])){
                st.pop();
                k--;
           }
           st.push(num[i]);
        }
        while(k--){
            st.pop();
        }
        string rev="";
        while(!st.empty()){
            rev += st.top();
            st.pop();
        }
        reverse(rev.begin(),rev.end());
        int idx = 0;
        while(idx < rev.length() && rev[idx] == '0'){
            idx++;
        }
        if(idx == rev.length())
            return "0";
        return rev.substr(idx);
    }
};