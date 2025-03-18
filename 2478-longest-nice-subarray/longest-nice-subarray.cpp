class Solution {
public:
    bool isValid(int val,vector<bool>&usedbits){
        for(int i=0;i<32;i++){
            if((val >> i) & 1){
                if(usedbits[i])
                    return false;
            }
        }
        return true;
    }

    void removenumber(vector<bool>&usedbits,int val){
        for(int i=0;i<32;i++){
            if((val >> i) & 1){
                usedbits[i] = false;
            }
        }
    }

    void addnumber(vector<bool>&usedbits,int val){
        for(int i=0;i<32;i++){
            if((val >> i) & 1){
                usedbits[i] = true;
            }
        }
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<bool>usedbits(32,false);
        int st = 0;
        int end = 0;
        while(end < n){
            while(!isValid(nums[end],usedbits)){
                removenumber(usedbits,nums[st]);
                st++;
            }
            addnumber(usedbits,nums[end]);
            ans = max(ans,end-st+1);
            end++;
        }
        return ans;
    }
};