class Solution {
    void generateSubsetSum(vector<int>& nums, vector<vector<int>>& subsetSum, int st, int n){

        for(int i=0;i<(1 << n);i++){
            int cnt = 0;
            int sum = 0;
            for(int j=0;j<n;j++){
                if((i >> j) & 1){
                    sum += nums[j+st];
                    cnt++;
                }
            }
            subsetSum[cnt].push_back(sum);
        }
    }

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<vector<int>> leftSum(n+1);
        vector<vector<int>> rightSum(n+1);
        int total = accumulate(nums.begin(),nums.end(),0);
        generateSubsetSum(nums,leftSum,0,n);
        generateSubsetSum(nums,rightSum,n,n);
        int ans = INT_MAX;

        for(int k=0;k<=n;k++){
            auto& left = leftSum[k];
            auto& right = rightSum[n-k];

            sort(right.begin(),right.end());

            for(auto &L : left){
                int target = total/2 - L;
                int lo = 0;
                int hi = right.size()-1;
                int pos = hi;
                while(lo <= hi){
                    int mid = (lo + (hi-lo)/2);
                    if(right[mid] >= target){
                        pos = mid;
                        hi = mid - 1;
                    }
                    else
                        lo = mid +1;
                }

                if(pos < right.size()){
                    int sum1 = L + right[pos];
                    int sum2 = total - sum1;
                    ans = min(ans,abs(sum1-sum2));
                }
                if(pos > 0){
                    int sum1 = L + right[pos-1];
                    int sum2 = total - sum1;
                    ans = min(ans,abs(sum1-sum2));
                }
            }
        }

        return ans;
    }
};