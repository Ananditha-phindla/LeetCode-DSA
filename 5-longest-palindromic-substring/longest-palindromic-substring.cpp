class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        string ans = "";
        if (s.length() == 1){
            return s ;
        }
        int sum = 0;
        for(int i=0;i<len;i++){
            int p1 = i,p2 = i;
            while(p1 >= 0 && p2 <= len && s[p1] == s[p2]){
                if((p2-p1+1) > sum){
                    ans = s.substr(p1,p2-p1+1);;
                    sum = p2-p1+1;
                }
                p1--;
                p2++;
            }
            p1 = i;
            p2 = i+1;
           while(p1 >= 0 && p2 <= len && s[p1] == s[p2]){
                if(p2-p1+1 > sum){
                    ans=s.substr(p1,p2-p1+1);;
                    sum = p2-p1+1;
                }
                p1--;
                p2++;
            }
           // ans=s.substr(p2-p1-1);
        }
        return ans;
    }
};