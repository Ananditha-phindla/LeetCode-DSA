class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "";
        string curr;
        while(ss >> curr){
            ans = curr + " " + ans;
        }
        ans.pop_back();
        return ans;
    }
};