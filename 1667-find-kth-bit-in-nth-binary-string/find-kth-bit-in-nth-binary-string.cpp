class Solution {
public:
    char solve(int n, int k,string s){
        if(n == 0 || s.length() >= k)
            return s[k-1];
        int size = s.length();
        s += "1";
        for(int i=size-1;i>=0;i--){
           if(s[i] == '0')
                s += '1';
            else
                s += '0';
        }
        cout << s << " ";
        return solve(n-1,k,s);
    }
    char findKthBit(int n, int k) {
        return solve(n-1,k,"0");
    }
};