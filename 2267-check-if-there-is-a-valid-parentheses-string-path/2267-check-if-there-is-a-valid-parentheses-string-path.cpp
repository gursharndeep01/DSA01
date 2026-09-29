class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool call(vector<vector<char>> &grid,int i,int j, int count, int &n,int &m){
        if(grid[i][j]==')') count--;
        else count++;
        if(count<0) return false;
        if(i==n-1 && j==m-1) return count==0;
        if(dp[i][j][count]!=-1) return dp[i][j][count];
        bool ans1=false,ans2=false;
        if(i<n-1) ans1= call(grid,i+1,j,count,n,m);
        if(j<m-1) ans2= call(grid,i,j+1,count,n,m);
        return dp[i][j][count]= ans1||ans2;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n= grid.size(),m=grid[0].size();
        if(grid[0][0]!='(' || grid[n-1][m-1]!=')') return false;
        dp.assign(n,vector<vector<int>>(m,vector<int>(m+n+1,-1)) );
        return call(grid,0,0,0,n,m);
    }
};