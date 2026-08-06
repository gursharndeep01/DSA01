class Solution {
public:
    int n;
    bool canReach(vector<vector<int>>& grid, int t) {
        if (grid[0][0] > t) return false;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i == n-1 && j == n-1) return true;
            for (auto& d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n 
                    && !visited[ni][nj] && grid[ni][nj] <=t) {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        return visited[n-1][n-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = 0, right = n * n - 1;
        while (low < right) {
            int t = low + (right - low) / 2;
            if (canReach(grid, t)) right = t;
            else low = t + 1;
        }
        return low;
    }
};