class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        vector<vector<vector<int>>> 
        dp(m, vector<vector<int>>(n, vector<int>(3,INT_MIN)));
        dp[0][0][2]=coins[0][0];
        if(coins[0][0]<0) dp[0][0][1]=0;
        for(int i=1;i<m;i++){
            for(int k=0;k<3;k++){
                if(dp[i-1][0][k]==INT_MIN) continue;
                dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k] + coins[i][0]);
                if(coins[i][0] < 0 && k > 0)
                    dp[i][0][k-1] = max(dp[i][0][k-1], dp[i-1][0][k]);
            }
        }
        for(int i=1;i<n;i++){
            for(int k=0;k<3;k++){
                if(dp[0][i-1][k]==INT_MIN) continue;
                dp[0][i][k] = max(dp[0][i][k], dp[0][i-1][k] + coins[0][i]);
                if(coins[0][i] < 0 && k > 0)
                    dp[0][i][k-1] = max(dp[0][i][k-1], dp[0][i-1][k]);
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                for(int k=0;k<3;k++){
                    int maxi=max(dp[i-1][j][k],dp[i][j-1][k]);
                    if(maxi==INT_MIN) continue;
                    dp[i][j][k] = max(dp[i][j][k], maxi + coins[i][j]);
                    if(coins[i][j] < 0 && k > 0)
                        dp[i][j][k-1] = max(dp[i][j][k-1], maxi);
                    }
                }
            }
        return max({dp[m-1][n-1][0],dp[m-1][n-1][1],dp[m-1][n-1][2]});
    }
};