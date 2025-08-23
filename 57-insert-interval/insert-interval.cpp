class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        if(intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }

        int n = intervals.size();
        bool f = false;
        int p1 = 0;
        while(p1 < n){
            if(!f && ((newInterval[0] >= intervals[p1][0] && newInterval[0] <= intervals[p1][1]) || (intervals[p1][0] >= newInterval[0] && intervals[p1][0] <= newInterval[1]))){
                f = true;
                int l = min(newInterval[0],intervals[p1][0]);
                int r = max(newInterval[1],intervals[p1][1]);
                while(p1 < n && intervals[p1][0] <= r){
                    r = max(r,intervals[p1][1]);
                    p1++;
                }
                p1--;
                ans.push_back({l,r});
            }
            else{
                if(f || newInterval[0] > intervals[p1][0]){
                    ans.push_back(intervals[p1]);
                }
                else{
                    ans.push_back(newInterval);
                    f = true;
                    p1--;
                }

            }
            p1++;
        }

        if(!f)
            ans.push_back(newInterval);
        return ans;
        
    }
};