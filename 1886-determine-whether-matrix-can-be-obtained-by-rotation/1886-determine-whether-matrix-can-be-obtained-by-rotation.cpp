class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int i=0;i<4;i++){
            if(mat==target) return true;
            for(int j=0;j<n;j++){
                for(int k=j;k<n;k++) swap(mat[j][k],mat[k][j]);
            }
            for(int j=0;j<n;j++){
                reverse(mat[j].begin(),mat[j].end());
            }
        }
        return false;
    }
};