class Solution {
public:
    bool isValid(int n,vector<string>&board,int i,int j){
        int r = i;
        while(r >= 0){
            if(board[r][j] == 'Q')
                return false;
            r--;
        }
        r = i;
        int c = j;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        r = i;
        c = j;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }
        return true;
    }
    void solve(int n,vector<string>&board,vector<vector<string>>&ans,int i){
        if(i == n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isValid(n,board,i,j)){
                board[i][j] = 'Q';
                solve(n,board,ans,i+1);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string curr(n,'.');
        vector<string>board(n,curr);
        solve(n,board,ans,0);
        return ans;
    }
};