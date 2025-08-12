class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;i++){
            int setbits = 0;
            for(int ele : nums){
                if((1 << i)&ele)
                    setbits++;
            }
            if(setbits%3)
                ans += (1 << i);
        }
        return ans;
    }
};