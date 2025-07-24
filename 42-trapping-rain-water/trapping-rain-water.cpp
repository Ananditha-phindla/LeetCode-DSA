class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int l = 1;
        int r = n-2;
        int ans = 0;
        while(l <= r){
            if(lmax <= rmax){
                if(height[l] >= lmax){
                    lmax = height[l];
                }
                else
                    ans += lmax - height[l];
                l++;
            }
            else{
                if(height[r] >= rmax){
                    rmax = height[r];
                }
                else
                    ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};