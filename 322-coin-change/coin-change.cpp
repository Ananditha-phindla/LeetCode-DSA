class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        queue<pair<int,int>> q;
        q.push({amount,0});
        vector<bool> vis(amount+1,false);
        vis[amount] = true;

        while(!q.empty()){
            int a = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(a == 0)
                return dist;
            for(int i=0;i<n;i++){
                if(a - coins[i] >= 0 && !vis[a - coins[i]]){
                    q.push({a-coins[i],dist+1});
                    vis[a - coins[i]] = true;
                }
            }
        }
        return -1;
    }
};