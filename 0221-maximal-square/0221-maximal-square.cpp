class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m= matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int max_size=0;
        if(matrix[0][0]=='1'){
            dp[0][0]=1;
            max_size=1;
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0]=='0') dp[i][0]=0;
            else {
                dp[i][0]=1;
                max_size=1;
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[0][i]=='0') dp[0][i]=0;
            else {
                dp[0][i]=1;
                max_size=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='0') dp[i][j]=0;
                else {
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
                    max_size=max(max_size,dp[i][j]);
                }
            }
        }
        return max_size*max_size;
    }
};