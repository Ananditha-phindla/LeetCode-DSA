class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;

        for(auto t : trips){
            int n = t[0];
            int f = t[1];
            int to = t[2];
            mp[f] += n;
            mp[to] -= n;
        }

        int sum = 0;
        int maxi = 0;
        for(auto it : mp){
            int k = it.first;
            mp[k] += sum;
            sum = mp[k];
            maxi = max(maxi,sum);
        }

        return (maxi <= capacity);
    }
};