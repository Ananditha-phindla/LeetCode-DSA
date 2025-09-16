class Solution {
public:
    string frequencySort(string s) {
        vector<int> lowCnt(26,0);
        vector<int> uppCnt(26,0);
        vector<int>digitCnt(10,0);

        for(auto ch : s){
            if(ch >= 'a' && ch <= 'z')
                lowCnt[ch-'a']++;
            else if(ch >= 'A' && ch <= 'Z')
                uppCnt[ch-'A']++;
            else
                digitCnt[ch-'0']++;
        }

        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(lowCnt[i] != 0)
                pq.push({lowCnt[i],char(i+97)});
            if(uppCnt[i] != 0)
                pq.push({uppCnt[i],char(i+65)});
            if(i < 10 && digitCnt[i] != 0)
                pq.push({digitCnt[i],char(i+48)});
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