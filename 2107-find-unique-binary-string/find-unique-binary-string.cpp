class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        int s = nums.size();
        unordered_set<int> myset;
        for(auto i : nums)
            myset.insert(stoi(i,0,2));
        int ans = 0;
        for(int i=0;i<(1<<n);i++){
            if(myset.find(i) == myset.end()){
                ans = i;
                break;
            }
        }
        bitset<32> binary(ans);
        string res = binary.to_string();
        string uni = res.substr(32-n);
        return uni;
    }
};