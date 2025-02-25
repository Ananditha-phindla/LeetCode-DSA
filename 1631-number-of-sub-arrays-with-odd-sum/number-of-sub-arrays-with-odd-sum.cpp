class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int m = 1e9 + 7;
        int n = arr.size();
        int prevodd = 0;
        int preveven = 0;
        long ans = 0;
        if(arr[0] % 2){
            ans = 1;
            prevodd = 1;
        }
        else
            preveven++;
        long prefsum = arr[0];
        for(int i=1;i<n;i++){
            prefsum += arr[i];
            if(prefsum % 2){
                ans += preveven;
                ans++;
                prevodd++;
            }
            else{
                ans += prevodd;
                preveven++;
            }
        }
        return ans%m;
    }
};