class Solution {
public:
    bool isValid(vector<int>& candies, long long k,long long limit){
        long long cnt = 0;
        for(int i : candies){
            cnt += (i/limit);
            if(cnt >= k)    
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(low <= high){
            int mid = low +(high-low)/2;
            if(isValid(candies,k,mid)){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};