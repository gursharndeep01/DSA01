class Solution {
public:
void dfs(int i,int j,vector<vector<char>>& board){
    if(i<0||j<0|| i>=board.size()|| j>=board[0].size() || board[i][j]!='O') return;
    board[i][j]='!';
    vector<int> vac={0,1,0,-1,0};
    for(int a=0;a<4;a++){
        dfs(vac[a]+i,vac[a+1]+j,board);
    }
}
    void solve(vector<vector<char>>& board) {
        int m= board.size(),n=board[0].size();
        if( m==0 ||n==0) return ;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][n-1]=='O') dfs(i,n-1,board);
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(0,i,board);
            if(board[m-1][i]=='O') dfs(m-1,i,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='!') board[i][j]='O';
            }
        }
    }
};