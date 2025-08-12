class Solution {
public:
    double myPow(double x, long n) {
        if(n < 0){
            return 1/myPow(x,-n);
        }
        double ans = 1;
        double res = x;
        while(n){
            if(n & 1){
                ans *= res;
            }
            res *= res;
            n = n >> 1;
        }
        return ans;
    }
};