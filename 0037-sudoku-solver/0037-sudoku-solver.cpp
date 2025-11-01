class Solution {
public:
    bool canplace(vector<vector<char>> & board,int row,int clm,char k){
        for(int i=0;i<9;i++) if(board[i][clm]==k) return false;
        for(int j=0;j<9;j++) if(board[row][j]==k) return false;
        int srow=(row/3)*3 , sclm=(clm/3)*3;
        for(int i=0;i<3;i++ ){
            for(int j=0;j<3;j++){
                if(board[i+srow][sclm+j]==k) return false; 
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> & board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(canplace(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)) return true;
                            board[i][j]='.';
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