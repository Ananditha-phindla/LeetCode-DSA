class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int num = start ^ goal;
        while(num > 0){
            ans++;
            num = num & (num-1);
        }
        return ans;
    }
};