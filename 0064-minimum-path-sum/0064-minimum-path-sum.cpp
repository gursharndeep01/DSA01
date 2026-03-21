class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> dummy (n);
        dummy[0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int t= i!=0 ?dummy[j]:INT_MAX;
                int l= j!=0? dummy[j-1]:INT_MAX;
                dummy[j]=grid[i][j]+min(t,l);
            }
        }
        return dummy[n-1];
    }
};