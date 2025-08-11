class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prev_evens = 0;
        int ans = 0;
        int i=0;
        int j = 0;
        int odds = 0;
        while(j < n){
            if(nums[j] % 2)
                odds++;
            while( i < j && (nums[i]%2 == 0 || odds > k)){
                if(nums[i]%2 == 0)
                    prev_evens++;
                else{
                    prev_evens = 0;
                    odds--;
                }
                i++;
            }
            if(odds == k)
                ans += (1 + prev_evens);
            j++;
        }
        return ans;
    }
};