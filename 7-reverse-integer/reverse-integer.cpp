class Solution {
public:
    int reverse(int x) {
        if(x < INT_MIN || x > INT_MAX)
            return 0;
        long y = x;
        if(x > 0){
        string s = to_string(x);
        s = string(s.rbegin(),s.rend()); 
        y = stoll(s);
        }
        else{
            y = abs(y);
            string s = to_string(y);
            s = string(s.rbegin(),s.rend());
            y = stoll(s);
            y = -y;
        }
        if(y < INT_MIN || y > INT_MAX)
            return 0;
        return y;
    }
};