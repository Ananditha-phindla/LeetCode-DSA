class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n_cnt = 0;
        int p_cnt = 0;
        for(auto i : nums){
            if(i > 0)
                p_cnt++;
            else if(i < 0)
                n_cnt++;
        }
        return max(p_cnt,n_cnt);
    }
};