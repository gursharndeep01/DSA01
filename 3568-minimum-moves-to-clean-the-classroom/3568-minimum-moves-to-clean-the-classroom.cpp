class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size(), cols = classroom[0].size();
        vector<vector<int>> litterIdx(rows, vector<int>(cols, -1));
        int sr = 0, sc = 0, litterCount = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                else if (classroom[i][j] == 'L') litterIdx[i][j] = litterCount++;
            }
        if (litterCount == 0) return 0;
        int fullMask = (1 << litterCount) - 1;
        vector<vector<vector<vector<bool>>>> visited(
            rows, vector<vector<vector<bool>>>(
                cols, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << litterCount, false))));
        queue<tuple<int,int,int,int>> q;
        q.push({sr, sc, energy, fullMask});
        visited[sr][sc][energy][fullMask] = true;
        int dirs[5] = {-1, 0, 1, 0, -1};
        int moves = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                auto [r, c, e, mask] = q.front(); q.pop();
                if (mask == 0) return moves;
                if (e <= 0) continue;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d], nc = c + dirs[d+1];
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                    if (classroom[nr][nc] == 'X') continue;
                    int ne = (classroom[nr][nc] == 'R') ? energy : e - 1;
                    int nmask = mask;
                    if (classroom[nr][nc] == 'L')
                        nmask &= ~(1 << litterIdx[nr][nc]);
                    if (!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};