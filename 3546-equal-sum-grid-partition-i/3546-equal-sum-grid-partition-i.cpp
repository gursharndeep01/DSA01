class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long total = 0;
        for (auto &row : grid) {
            for (auto &val : row) {
                total += val;
            }
        }
        if (total % 2 != 0) return false;
        vector<long long> rowSum(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowSum[i] += grid[i][j];
            }
        }
        long long curr = 0;
        for (int i = 0; i < n - 1; i++) {
            curr += rowSum[i];
            if (curr == total / 2) return true;
        }
        vector<long long> colSum(m, 0);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                colSum[j] += grid[i][j];
            }
        }
        curr = 0;
        for (int j = 0; j < m - 1; j++) {
            curr += colSum[j];
            if (curr == total / 2) return true;
        }
        return false;
    }
};