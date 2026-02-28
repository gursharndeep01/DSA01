class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n,vector<int> (n,-1));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int cnt = 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++)
                vec[top][j] = cnt++;
            top++;
            for (int i = top; i <= bottom; i++)
                vec[i][right] = cnt++;
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    vec[bottom][j] = cnt++;
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    vec[i][left] = cnt++;
                left++;
            }
        }
        return vec;
    }
};