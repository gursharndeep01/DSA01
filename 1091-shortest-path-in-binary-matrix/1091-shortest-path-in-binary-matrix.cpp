class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int i,j;
        vector<int> vecx = {1,1,1,0,0,-1,-1,-1};
        vector<int> vecy = {1,0,-1,1,-1,1,0,-1};
        grid[0][0]=1;
        while(!q.empty()){
            i=q.front().first; j= q.front().second;
            q.pop();
            for(int a=0;a<8;a++){
                int ii=i+vecx[a];
                int jj= j+vecy[a];
                if(ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                if(grid[ii][jj]==0) {
                    q.push({ii,jj});
                    grid[ii][jj]= grid[i][j]+1;
                    }
            }
        }
        return grid[n-1][n-1]==0 ? -1: grid[n-1][n-1];
    }
};