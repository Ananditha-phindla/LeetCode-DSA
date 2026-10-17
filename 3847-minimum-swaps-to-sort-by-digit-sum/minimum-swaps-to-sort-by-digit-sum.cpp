class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n){
            int r = n % 10;
            sum += r;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int sum = digitSum(nums[i]);
            pq.push({sum,nums[i]});
            mp[nums[i]] = i;
        }

        vector<int> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        int swps = 0;

        for(int i=0;i<n;i++){
            if(res[i] == nums[i])
                continue;
            swps++;
            mp[nums[i]] = mp[res[i]];
            mp[res[i]] = i;
            swap(nums[i],nums[mp[nums[i]]]);
        }

         return swps;

        
    }
};