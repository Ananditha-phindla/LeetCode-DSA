class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i] == 'I'){
                if(i == n-1 || s[i+1] == 'I')
                    ans += 1;
                else
                    ans -= 1;
                
            }
            else if(s[i] == 'V'){
                if(i == n-1 || s[i+1] == 'I' || s[i+1] == 'V')
                    ans += 5;
                else
                    ans -= 5;

            }
            else if(s[i] == 'X'){
                if(i == n-1 || s[i+1] == 'I' || s[i+1] == 'V' || s[i+1] == 'X')
                    ans += 10;
                else
                    ans -= 10;
            }
            else if(s[i] == 'L'){
                if(i == n-1 || s[i+1] == 'I' || s[i+1] == 'V' || s[i+1] == 'X' || s[i+1] == 'L' )
                    ans += 50;
                else
                    ans -= 50;
                
            }
            else if(s[i] == 'C'){
                if(i == n-1 || s[i+1] == 'I' || s[i+1] == 'V' || s[i+1] == 'X' || s[i+1] == 'L' || s[i+1] == 'C')
                    ans += 100;
                else
                    ans -= 100;
            }
            else if(s[i] == 'D'){
                if(i == n-1 || s[i+1] == 'I' || s[i+1] == 'V' || s[i+1] == 'X' || s[i+1] == 'L' || s[i+1] == 'C' || s[i+1] == 'D')
                    ans += 500;
                else
                    ans -= 500;
            }
            else{
                if(i == n-1 || s[i+1] == 'I' || s[i+1] == 'V' || s[i+1] == 'X' || s[i+1] == 'L' || s[i+1] == 'C' || s[i+1] == 'D' || s[i+1] == 'M')
                    ans += 1000;
            }
        }
        return ans;
    }
};