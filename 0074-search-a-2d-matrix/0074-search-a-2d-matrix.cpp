class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            int left=0,right=n-1;
            if(target<= matrix[i][right] && target>= matrix[i][left]){
                while(left<right){
                    int mid=(left+right+1)>>1;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target) left=mid;
                    else right=mid-1;
                }
                if(matrix[i][left] == target) return true;
            }
        }
        return false;
    }
};