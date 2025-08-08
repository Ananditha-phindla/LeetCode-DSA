class Solution {
public:
    int m = 1e9+7;
    long solve(int n){
        if(n == 1)
            return 2;
        long long p = (solve(n/2))%m;
         if(n % 2)
            return p * p * 2;
        return p * p;
    }
    int monkeyMove(int n) {
        long  val = solve(n);
        return (val - 2)%m;
    }
};