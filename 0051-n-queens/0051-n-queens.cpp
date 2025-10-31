class Solution {
public:
    bool canplace(vector<string> &vect,int i,int j,int n){
        for(int a=0;a<i;a++) if(vect[a][j]=='Q') return false;
        int a=i,b=j;
        while(a>=0 && b>=0){
            if(vect[a][b]=='Q') return false;
            a--;b--;
        }
        a=i;b=j;
        while(a>=0 && b<n){
            if(vect[a][b]=='Q') return false;
            a--;b++;
        }
        return true;
    }
    void place(int row,vector<string>&vect,vector<vector<string>>& vecp,int n){
        if(row==n){
            vecp.push_back(vect);
            return;
        }
        for(int clm=0;clm<n;clm++){
            if(canplace(vect,row,clm,n)){
                vect[row][clm]='Q';
                place(row+1,vect,vecp,n);
                vect[row][clm]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vect(n,string(n,'.'));
        vector<vector<string>> vecp;
        place(0,vect,vecp,n);
        return vecp;
    }
};