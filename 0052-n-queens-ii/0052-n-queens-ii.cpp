class Solution {
public:
    bool canplace(int i,int j,vector<vector<int>> &vec,int n){
        for(int k=0;k<n;k++) if(vec[k][j]==1) return false;
        for(int r = i-1, c = j-1; r >= 0 && c >= 0; r--, c--)
            if(vec[r][c] == 1) return false;
        for(int r = i-1, c = j+1; r >= 0 && c < n; r--, c++)
            if(vec[r][c] == 1) return false;
        return true;
    }
    void rec(int row,vector<vector<int>> & vec,int n,int &cnt){
        if(row==n) {
            cnt++;
            return;
        }
        for(int i=0;i<n;i++){
            if(canplace(row,i,vec,n)){
                vec[row][i]=1;
                rec(row+1,vec,n,cnt);
                vec[row][i]=0;
            }
        }
    }
    int totalNQueens(int n) {
        int cnt=0;
        vector<vector<int>> vec(n,vector<int> (n,0));
        rec(0,vec,n,cnt);
        return cnt;
    }
};