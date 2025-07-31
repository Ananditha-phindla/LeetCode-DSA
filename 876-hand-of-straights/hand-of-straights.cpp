class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0)
            return false;
        unordered_map<int,int>mp;
        for(int curr : hand){
            mp[curr]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i : mp){
            pq.push({i.first,i.second});
        }

        while(!pq.empty()){
            int prev = pq.top().first;
            vector<pair<int,int>>remaining;
            if(pq.top().second > 1)
                remaining.push_back({prev,pq.top().second-1});
            pq.pop();
            int s = groupSize - 1;
            while(s){
                int curr = pq.top().first;
                if(curr+1 != prev){
                    return false;
                }
                if(pq.top().second > 1){
                    remaining.push_back({curr,pq.top().second-1});
                }
                pq.pop();
                s--;
                prev = curr;
            }
            for(auto ele : remaining)
                pq.push(ele);

        }
        return true;

    }
};