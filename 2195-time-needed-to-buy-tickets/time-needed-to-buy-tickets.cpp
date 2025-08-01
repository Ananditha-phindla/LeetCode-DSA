class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();
        for(int i=0;i<=k;i++){
            time += min(tickets[k],tickets[i]);
        }
        for(int i=k+1;i<n;i++){
            if(tickets[i] >= tickets[k]){
                time += tickets[k]-1;
            }
            else
                time += tickets[i];
        }
        return time;
    }
};