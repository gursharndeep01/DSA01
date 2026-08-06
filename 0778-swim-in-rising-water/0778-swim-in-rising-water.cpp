class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int maxTime = 0;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int wt = top[0], i = top[1], j = top[2];
            maxTime = max(maxTime, wt);
            if (i == n-1 && j == n-1) return maxTime;
            for (auto& d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.push({grid[ni][nj], ni, nj});
                }
            }
        }
        return maxTime;
    }
};