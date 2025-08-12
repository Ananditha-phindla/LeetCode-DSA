class Solution {
public:
    bool isPowerOfTwo(long n) {
        return ((n&(n-1)) == 0 && n != 0);
    }
};