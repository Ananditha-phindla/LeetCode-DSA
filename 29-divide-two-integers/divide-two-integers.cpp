class Solution {
public:
    int divide(long dividend, long divisor) {
        if((dividend == INT_MIN || dividend == INT_MAX) && divisor == 1)
            return dividend;
        if(dividend == divisor)
            return 1;
        bool isPositive = (dividend < 0 == divisor < 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        long q = 0;
        for(long i=30;i>=0;i--){
            if((long)(1L<<i)*divisor <= dividend){
                q += (1 << i);
                dividend -= (long)(divisor * (1 << i));
            }
        }
        return (isPositive) ? q : -q;
    }
};