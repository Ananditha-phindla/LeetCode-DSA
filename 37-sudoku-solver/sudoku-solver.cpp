class Solution {
public:
    bool isValid(vector<vector<char>>& board,int r,int c,int num){
      for(int j=0;j<9;j++){
        if(char(num+'0') == board[r][j])
          return false;
      }

      for(int i=0;i<9;i++){
        if(char(num+'0') == board[i][c])
          return false;
      }

      int s = (r/3) * 3;
      int e = (c/3) * 3;
      for(int i=s;i<s+3;i++){
        for(int j=e;j<e+3;j++){
          if(char(num+'0') == board[i][j])
            return false;
        }
      }

      return true;
    }

    bool solve(vector<vector<char>>& board){
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          if(board[i][j] == '.'){
            for(int num=1;num<=9;num++){
              if(isValid(board,i,j,num)){
                board[i][j] = char(num+'0');
                if(solve(board))
                  return true;
                board[i][j] = '.';
              }
            }
            return false;
          }
        }
      }

      return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};