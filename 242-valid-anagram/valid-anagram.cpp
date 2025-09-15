class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m)
            return false;

        vector<int> scnt(26,0);
        vector<int> tcnt(26,0);
        for(int i=0;i<n;i++){
            scnt[s[i] - 'a']++;
            tcnt[t[i] - 'a']++;
        }

        for(int i=0;i<26;i++){
            if(scnt[i] != tcnt[i])
                return false;
        }
        return true;
    }
};