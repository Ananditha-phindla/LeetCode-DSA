class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int>cnt(10,0);
        while(n > 0){
            cnt[n%10]++;
            n /= 10;
        }
        for(int i=0;i<32;i++){
            vector<int>twoPow(10,0);
            int curr = (1 << i);
            while(curr > 0){
                twoPow[curr%10]++;
                curr /= 10;
            }
            bool f = true;
            for(int i=0;i<10;i++){
                if(cnt[i] != twoPow[i]){
                    f = false;
                    break;
                }
            }
            if(f)
                return true;
        }
        return false;
    }
};