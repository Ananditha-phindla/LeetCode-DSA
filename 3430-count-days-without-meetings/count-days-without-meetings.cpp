class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();
        int s = meetings[0][0];
        int e = meetings[0][1];
        ans += (s - 1);
        for(auto i : meetings){
            cout << i[0] << " " << i[1] << " ";
        }
        for(int i=1;i<n;i++){
            if(meetings[i][0] > e){
                ans += (meetings[i][0] - e - 1);
                e = meetings[i][1];
            }
            else if(meetings[i][1] > e)
                e = meetings[i][1];
        }
        ans += (days - e);
        return ans;
    }
};