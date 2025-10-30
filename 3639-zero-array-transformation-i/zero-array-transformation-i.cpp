class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(int i=n-1;i>0;i--){
            nums[i] -= nums[i-1];
        }

        for(auto q : queries){
            nums[q[0]]--;
            if(q[1]+1 < n)  
                nums[q[1]+1]++;
        }


        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
            if(nums[i] > 0)
                return false;
        }

        return (nums[0] <= 0);

    }
};