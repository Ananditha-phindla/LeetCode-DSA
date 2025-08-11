class Solution {
public:
    bool check(unordered_map<char,int>&mp,unordered_map<char,int>&mpT){
        for(auto i : mpT){
            char ch = i.first;
            int freq = i.second;
            if(!mp.count(ch) || mp[ch] < freq)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int>mpT;
        for(char c : t){
            mpT[c]++;
        }
        int n = s.length();
        int i = 0;
        int j = 0;
        string ans = "";
        unordered_map<char,int>mp;
        while(j < n){
            mp[s[j]]++;
            while(i < j && (!mpT.count(s[i]) || mp[s[i]] > mpT[s[i]])){
                if(mp[s[i]] > 1)
                    mp[s[i]]--;
                else
                    mp.erase(s[i]);
                i++;
            }
            if(check(mp,mpT)){
                if(ans == "" || ans.length() > j-i+1)
                    ans = s.substr(i,(j-i+1));
            }
            j++;
        }
        return ans;
    }
};