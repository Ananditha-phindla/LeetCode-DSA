class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;
        int i = 0;
        while(n > 0){
            n = n >> 1;
            ans += (2 << i);
            i++;
        }
        return ans/2;
    }
};