class Solution {
public:
    bool valid(int target,string s,int idx,int prevsum){
        if(idx == s.length()){
            return (prevsum == target);
        }
        int curr = 0;
        for(int i=idx;i<s.length();i++){
            curr = curr*10 + (s[i] - '0');
            if(valid(target,s,i+1,prevsum+curr))
                return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
           if(valid(i,to_string(i*i),0,0))
                ans += (i*i);
        }
        return ans;
    }
};