class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        deque<pair<int,int>>dq;
        for(int i=0;i<n;i++){
            dq.push_back({tickets[i],i});
        }
        int time = 0;
        while(true){
            if(dq.front().second == k && dq.front().first == 1){
                time++;
                break;
            }
            int f = dq.front().first;
            int i = dq.front().second;
            dq.pop_front();
            if(f-1 > 0)
                dq.push_back({f-1,i});
            time++;
        }
        return time;
    }
};