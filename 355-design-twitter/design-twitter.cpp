class Twitter {
public:
    vector<vector<bool>>follow_mat;
    unordered_map<int,vector<pair<int,int>>> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int time;
    Twitter() {
        follow_mat.resize(501,vector<bool>(501,false));
        mp.clear();
        time = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        for(int i=0;i<501;i++){
            if(i == userId || follow_mat[userId][i]){
                for(auto t : mp[i]){
                    pq.push(t);
                    cout << t.first << endl;
                    if(pq.size() > 10)
                        pq.pop();
                }
            }
        }
        vector<int>ans(pq.size());
        int i= pq.size()-1;
        while(!pq.empty()){
            ans[i] = pq.top().second;
            i--;
            pq.pop();
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        follow_mat[followerId][followeeId] = true;
        
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_mat[followerId][followeeId] = false;
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */