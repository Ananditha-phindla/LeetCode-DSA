class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].length();
        int m = strs.size();
        string ans = "";
        bool f = false;
        for(int i=0;i<n;i++){
            char curr = strs[0][i];
            for(int j=1;j<m;j++){
                if(curr != strs[j][i]){
                    f = true;
                    break;
                }
            }
            if(f)
                break;
            ans += curr;
        }
        return ans;
    }
};