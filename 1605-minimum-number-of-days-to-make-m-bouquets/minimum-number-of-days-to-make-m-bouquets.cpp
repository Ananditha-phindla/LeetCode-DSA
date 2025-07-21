class Solution {
public:
    bool isValid(vector<int>& b, int m, int k,int mid){
        int cnt = 0;
        int bloomed = 0;
        for(int i=0;i<b.size();i++){
            if(b[i] <= mid){
                bloomed++;
            }
            else{
                bloomed = 0;
            }
            if(bloomed == k){
                cnt++;
                bloomed = 0;
            }
        }
        return (cnt >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()/k < m )
            return -1;
        int lo = *min_element(bloomDay.begin(),bloomDay.end());
        int hi = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = hi;
        while(lo <= hi){
            int mid = (lo + (hi-lo)/2);
            if(isValid(bloomDay,m,k,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};