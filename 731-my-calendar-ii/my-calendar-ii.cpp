class MyCalendarTwo {
    map<int,int> mp;
public:
    MyCalendarTwo() {
        mp.clear();
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int sum = 0;
        for(auto it : mp){
            int k = it.first;
            sum += mp[k];
            if(sum > 2){
                mp[startTime]--;
                mp[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */