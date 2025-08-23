class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = ratings.size();
        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }

        vector<int>candies(n,0);
        while(!pq.empty()){
            int r = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(candies[idx] == 0)
                candies[idx] = 1;
            if(idx-1 >= 0 && ratings[idx-1] > r)
                candies[idx-1] = max(candies[idx-1],candies[idx]+1);
            if(idx+1 < n && ratings[idx+1] > r)
                candies[idx+1] = max(candies[idx+1],candies[idx]+1);
        }

        int ans = 0;
        for(int i : candies){
            ans += i;
        }
        return ans;
    }
};