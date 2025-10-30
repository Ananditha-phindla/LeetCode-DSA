class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        int n = people.size();
        vector<int> ans(n);

        for(auto f : flowers){
            mp[f[0]]++;
            mp[f[1]+1]--;
        }

        int sum = 0;

        for(auto it : mp){
            int k = it.first;
            mp[k] += sum;
            sum = mp[k];
        }

        for(int i=0;i<n;i++){
            if(mp.count(people[i]))
                ans[i] = mp[people[i]];
            else{
                auto it = mp.lower_bound(people[i]);
                if(it == mp.begin())
                    ans[i] = 0;
                else
                    ans[i] = prev(it)->second;
            }
        }
        return ans;
    }
};