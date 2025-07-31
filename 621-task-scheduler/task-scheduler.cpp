class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        vector<int>cnt(26,0);
        int total = 0;
        for(int i=0;i<size;i++){
            cnt[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(cnt[i])
                pq.push(cnt[i]);
        }

        while(!pq.empty()){
            int cycle = n+1;
            vector<int>remaining;
            while(cycle && !pq.empty()){
                int a = pq.top();
                pq.pop();
                cycle--;
                total++;
                if(a > 1)
                    remaining.push_back(a-1);
            }
            for(auto ele : remaining)
                pq.push(ele);
            if(!pq.empty())
                total += cycle;
        }
        return total;
    }
};