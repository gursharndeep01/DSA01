class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rvec(9,vector<int>(9,0));
        vector<vector<int>> cvec(9,vector<int>(9,0));
        vector<vector<int>> bvec(9,vector<int>(9,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] =='.') continue;
                int n= board[i][j]-'1';
                int idx=(i/3)*3+(j/3);
                if(rvec[i][n] || cvec[j][n]|| bvec[idx][n]) return false;
                rvec[i][n]=1;
                cvec[j][n]=1;
                bvec[idx][n]=1;
            }
        }
        return true;
    }
};