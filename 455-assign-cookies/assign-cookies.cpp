class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int p1 = 0;
        int p2 = 0;
        int ans = 0;
        while(p1 < n && p2 < m){
            if(g[p1] <= s[p2]){
                ans++;
                p1++;
                p2++;
            }
            else{
                p2++;
            }
        }
        return ans;
    }
};