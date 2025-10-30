class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        
        for(auto l : logs){
            int b = l[0];
            int d = l[1];
            mp[b]++;
            mp[d]--;
        }

        int sum = 0;
        int maxi = 0;
        int ans;
        for(auto it : mp){
            int k = it.first;
            mp[k] += sum;
            sum = mp[k];
            if(maxi < sum){
                sum = maxi;
                ans = k;
            }
        }

        return ans;
    }
};