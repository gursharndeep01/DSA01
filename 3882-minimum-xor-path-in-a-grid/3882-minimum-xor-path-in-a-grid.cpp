class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<unordered_set<int>>> vec(m,vector<unordered_set<int>> (n));
        vec[0][0].insert(grid[0][0]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(i>0){
                    for(int a:vec[i-1][j]) vec[i][j].insert(grid[i][j]^a);
                }
                if(j>0){
                    for(int a:vec[i][j-1]) vec[i][j].insert(grid[i][j]^a);
                }
            }
        }
        return *min_element(vec[m-1][n-1].begin(),vec[m-1][n-1].end());
    }
};