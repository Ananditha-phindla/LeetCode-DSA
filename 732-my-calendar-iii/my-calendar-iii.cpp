class MyCalendarThree {
    map<int,int> mp;
public:
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int sum = 0;
        int maxi = 0;
        for(auto it : mp){
            int k = it.first;
            sum += mp[k];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */