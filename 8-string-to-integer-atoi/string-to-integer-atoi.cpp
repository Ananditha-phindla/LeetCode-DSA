class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        while(i < n && s[i] == ' ')
            i++;
        if(i == n)
            return 0;
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
            i++;
        long long num = 0;
        while(i < n && isdigit(s[i])){
            num *= 10;
            num += (s[i] - '0');
            if(num * sign <= INT_MIN)
                return INT_MIN;
            if(num * sign >= INT_MAX)
                return INT_MAX;
            i++;
        }
        return sign * num;
        
    }
};