class Solution {
public:
    int count(int i,int j,int id,vector<vector<int>> &grid,int n){
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j]=id;
        int size=1;
        size += count(i - 1, j, id, grid, n);
        size += count(i + 1, j, id, grid, n);
        size += count(i, j - 1, id, grid, n);
        size += count(i, j + 1, id, grid, n);
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
    int n= grid.size();
    unordered_map<int ,int> idsmap;
    int id=2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                int size=count(i,j,id,grid,n);
                idsmap[id]=size;
                id++;
            }
        }
    }
    int maximum = 0;
    for (auto& [k, v] : idsmap) maximum = max(maximum, v);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> neighborIds;
                    if (i > 0 && grid[i-1][j] > 1) neighborIds.insert(grid[i-1][j]);
                    if (i < n-1 && grid[i+1][j] > 1) neighborIds.insert(grid[i+1][j]);
                    if (j > 0 && grid[i][j-1] > 1) neighborIds.insert(grid[i][j-1]);
                    if (j < n-1 && grid[i][j+1] > 1) neighborIds.insert(grid[i][j+1]);
                    int total = 1;  
                    for (int nid : neighborIds) total += idsmap[nid];
                    maximum = max(maximum, total);
                }
            }
        }
    return maximum;
    }
};