class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        int m= group.size();
        vector<vector<int>> dp(n+1,vector<int>(minProfit+1,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int g=n;g>=group[i];g--){
                for(int p=minProfit;p>=0;p--){
                    int pro= max(0,p-profit[i]);
                    dp[g][p]= (dp[g][p] +dp[g-group[i]][pro])%MOD;
                }
            }
        }
        int count=0;
        for(int i=0;i<=n;i++){
            count= (count+dp[i][minProfit])%MOD;
        }
        return count;
    }
};