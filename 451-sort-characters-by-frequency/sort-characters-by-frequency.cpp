class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto ch : s)
            mp[ch]++;

        vector<string>bucket(s.length(),"");

        for(auto i : mp){
            int freq = i.second;
            while(freq--)
                bucket[i.second-1] += i.first;
        }

        string ans = "";

        for(int i=bucket.size()-1;i>=0;i--){
            if(!bucket[i].empty())
                ans += bucket[i];
        }

        return ans;
    }
};