class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 = INT_MIN;
        int c2 = INT_MIN;
        int f1 = 0;
        int f2 = 0;
        for(int i=0;i<n;i++){
            if(f1 == 0 && c2 != nums[i]){
                c1 = nums[i];
                f1 = 1;
            }
            else if(f2 == 0 && c1 != nums[i]){
                c2 = nums[i];
                f2 = 1;
            }
            else if(nums[i] == c1){
                f1++;
            }
            else if(nums[i] == c2)
                f2++;
            else{
                f1--;
                f2--;
            }
        }

        f1 = 0, f2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == c1)
                f1++;
            else if(nums[i] == c2)
                f2++;
        }
        vector<int> ans;
        if(f1 > n/3)\
            ans.push_back(c1);
        if(f2 > n/3)
            ans.push_back(c2);
        return ans;

    }
};