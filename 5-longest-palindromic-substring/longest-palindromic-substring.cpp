class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1)
            return s;
        int len = 0;
        int l = 0, r = 0;
        for(int i=0;i<n;i++){
            int p1 = i,p2 = i;
            while(p1 >= 0 && p2 < n && s[p1] == s[p2]){
                if(len < (p2-p1+1)){
                len = (p2 - p1 + 1);
                l = p1;
                r = p2-p1+1;
            }
                p1--;
                p2++;
            }
            p1 = i,p2 = i+1;
            while(p1 >= 0 && p2 < n && s[p1] == s[p2]){
                if(len < (p2-p1+1)){
                len = p2 - p1 + 1;
                l = p1;
                r = p2-p1+1;
            }
                p1--;
                p2++;
            }
        }
        return s.substr(l,r);
    }
};