class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            vector<int> cnt(26,0);
            for(int j=i;j<n;j++){
                cnt[s[j] - 'a']++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(int i=0;i<26;i++){
                    if(cnt[i] != 0){
                        maxi = max(maxi,cnt[i]);
                        mini = min(mini,cnt[i]);
                    }
                }
                ans += (maxi - mini);
            }
        }

        return ans;
    }
};