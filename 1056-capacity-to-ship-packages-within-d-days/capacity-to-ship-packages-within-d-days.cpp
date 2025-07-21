class Solution {
public:
    bool isValid(vector<int>& w, int d,int mid){
        int sum = 0;
        for(int i=0;i<w.size();i++){
            if(w[i] > mid)
                return false;
            if(sum+w[i] > mid){
                d--;
                sum = w[i];
            }
            else
                sum += w[i];
        }
        if(sum <= mid)
            d--;
        return (d >= 0);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0;
        int hi = accumulate(weights.begin(),weights.end(),0);
        int ans = hi;
        while(lo <= hi){
            int mid = (lo + (hi-lo)/2);
            if(isValid(weights,days,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};