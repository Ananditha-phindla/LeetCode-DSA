class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>myset;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j < s.length()){
            if(myset.count(s[j])){
                while(s[i] != s[j]){
                    myset.erase(s[i]);
                    i++;
                }
                i++;
                j++;
            }
            else{
                myset.insert(s[j]);
                j++;
                ans = max(ans,j-i);
            }
        }
        return ans;
    }
};