class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(((n%2!=0)|| n<1) && n!=1)
        return false;
        if(n==1)
        return true;
        return(isPowerOfTwo(n/2));
    }
};