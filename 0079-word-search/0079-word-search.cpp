class Solution {
public:
    bool yes(vector<vector<char>>& board, string word,int i,int j,int indx){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||indx>=word.size()||board[i][j]!=word[indx]) return false ;
        if(indx==(word.size()-1)) return true;
        char tempu=board[i][j];
        board[i][j]='?';
        vector<int> arr={0,-1,0,1,0};
        for(int k=0;k<4;k++){
            if(yes(board,word,i+arr[k],j+arr[k+1],indx+1)){
                board[i][j]=tempu ;
                return true;
            }
        }
        board[i][j]=tempu;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++)
                if(yes(board,word,i,j,0)) return true;
        }
        return false;
    }
};