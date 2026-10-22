class Solution {
public:
    int chartoint(char ch){
        return ch - '0';
    }

    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0')
            return "0";
        if(num1.length() < num2.length())
            return multiply(num2,num1);
        string ans(401,'0');
        int n = num2.length();
        int m = num1.length();
        int carry = 0;
        
        for(int i = n-1;i>=0;i--){
            int idx = 401 - (n - i);
            for(int j=m-1;j>=0;j--){
                int val = chartoint(ans[idx]) + (chartoint(num2[i]) * chartoint(num1[j]))+ carry;
                ans[idx] = (val % 10) + '0';
                carry = val/10;
                idx--;
            }
            while(carry > 0){
                ans[idx] = (carry % 10) + '0';
                carry /= 10;
            }
        }
        
        int i = 0;
        while(ans[i] == '0'){
            i++;
        }
        return ans.substr(i);
    }
};