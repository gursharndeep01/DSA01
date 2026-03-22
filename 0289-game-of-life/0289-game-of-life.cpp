class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m= board.size(),n=board[0].size();
        vector<int> x={-1,-1,-1,0,0,1,1,1};
        vector<int> y={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int t1=0;
                for(int k=0;k<8;k++){
                    int ni= i+x[k];
                    int nj= j+y[k];

                    if(nj>=0 && nj<n && ni>=0 && ni< m){
                        if(abs(board[ni][nj])==1) t1++;
                    }
                }
                if(board[i][j]==1){
                    if(t1>3 || t1<2) board[i][j]=-1;
                }
                else 
                if(t1==3) board[i][j]= 11;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]>0) board[i][j]=1;
                else board[i][j]=0;
            }
        }   
    }
};