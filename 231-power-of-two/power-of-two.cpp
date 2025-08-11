class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while(n > 0){
            if(n & 1)
                cnt++;
            if(cnt > 1)
                return false;
            n = n >> 1;
        }
        return (cnt == 1);
    }
};