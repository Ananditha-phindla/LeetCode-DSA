class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i,int j, int k, vector<vector<bool>>&vis){
        if(k == word.length())
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k] || vis[i][j])
            return false;
        
        vis[i][j] = true;
        bool down = solve(board,word,i+1,j,k+1,vis);
        bool up = solve(board,word,i-1,j,k+1,vis);
        bool left = solve(board,word,i,j-1,k+1,vis);
        bool right = solve(board,word,i,j+1,k+1,vis);
        vis[i][j] = false;
        return down || up || left || right;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && solve(board,word,i,j,0,vis))
                    return true;
            }
        }
        return false;
    }
};