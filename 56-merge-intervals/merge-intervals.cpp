class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i = 0;
        int n = intervals.size();
        vector<vector<int>>ans;

        while(i < n){
            int s = intervals[i][0];
            int e = intervals[i][1];
            while(i < n && intervals[i][0] <= e){
                e = max(e,intervals[i][1]);
                i++;
            }
            ans.push_back({s,e});
        }

        return ans;
    }
};