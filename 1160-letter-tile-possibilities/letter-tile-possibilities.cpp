class Solution {
public:
    void sequence(unordered_set<string> &res, vector<bool> &visited,string &tiles, string cur){
        res.insert(cur);
        for(int i=0;i<tiles.length();i++){
            if(!visited[i]){
                visited[i] = true;
                sequence(res,visited,tiles,cur+tiles[i]);
                visited[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        unordered_set<string> res;
        vector<bool> visited(n,false);
        sequence(res,visited,tiles,"");
        return res.size()-1;
    }
};