class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<n;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            vector<string> temp;
            for(int i=0;i<it.second.size();i++){
                temp.push_back(strs[it.second[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};