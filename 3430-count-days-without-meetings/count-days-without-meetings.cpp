class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int,int> mp;

        for(auto m : meetings){
            mp[m[0]]++;
            mp[m[1]+1]--;
        }
        
        int cnt = mp.begin()->first-1;
        int sum = 0;

        for(auto it : mp){
            int k = it.first;
            mp[k] += sum;
            sum = mp[k];
            if(sum == 0){
                auto curr_it = mp.find(k);
                auto next_it = next(curr_it);
                if(next_it != mp.end())
                    cnt += (next_it->first - k);
                else
                    cnt += (days - k + 1);
            }

        }

        
        return cnt;
    }
};