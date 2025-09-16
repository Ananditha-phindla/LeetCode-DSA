class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int,char>>pq;
        for(auto i : mp){
            pq.push({i.second,i.first});
        }

         string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            ans.append(freq,ch);
        }
        return ans;
    }
};