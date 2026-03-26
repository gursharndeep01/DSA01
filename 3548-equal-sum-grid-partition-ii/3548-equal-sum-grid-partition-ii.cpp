class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        long long part1;
        long long diff;
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<long long> prt1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 4; k++) {
            prt1.clear();
            prt1.insert(0);
            part1 = 0;
            m = grid.size();
            n = grid[0].size();
            if (m < 2) {
                grid = rotation(grid);
                continue;
            }
            if (n == 1) {
                for (int i = 0; i < m - 1; i++) {
                    part1 += grid[i][0];
                    diff = part1 * 2 - total;
                    if (diff == 0 || diff == grid[0][0] || diff == grid[i][0]) {
                        return true;
                    }
                }
                grid = rotation(grid);
                continue;
            }
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    prt1.insert(grid[i][j]);
                    part1 += grid[i][j];
                }
                diff = part1 * 2 - total;
                if (i == 0) {
                    if (diff == 0 || diff == grid[0][0] || diff == grid[0][n - 1]) {
                        return true;
                    }
                    continue;
                }
                if (prt1.contains(diff)) {
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }
};