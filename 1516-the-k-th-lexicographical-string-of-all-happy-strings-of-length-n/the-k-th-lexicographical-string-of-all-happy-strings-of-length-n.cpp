class Solution {
public:
    void generate(int n,string curr,vector<string>&poss){
        if(curr.length() == n){
            poss.push_back(curr);
            return;
        }
        for(char i='a';i<='c';i++){
            if(!curr.empty() && curr.back() == i)
                continue;
            generate(n,curr+i,poss);
        }
    }
    string getHappyString(int n, int k) {
        string curr;
        vector<string>poss;
        generate(n,curr,poss);
        if(poss.size() < k)
            return "";
        sort(poss.begin(),poss.end());
        return poss[k-1];
    }
};