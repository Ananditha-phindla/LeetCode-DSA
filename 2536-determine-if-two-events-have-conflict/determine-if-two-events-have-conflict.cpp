class Solution {
    int getMinutes(string &s){
        int hours = (s[0] -'0') * 10 + (s[1] - '0');
        int mins = (s[3] - '0') * 10 + (s[4] - '0');

        return hours*60 + mins;
    }

public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int e1s = getMinutes(event1[0]);
        int e1e = getMinutes(event1[1]);
        int e2s = getMinutes(event2[0]);
        int e2e = getMinutes(event2[1]);

        if(e1s < e2s){
            if(e1e >= e2s)
                return true;
            return false;
        }

        if(e2e >= e1s)
            return true;
        return false;

    }
};