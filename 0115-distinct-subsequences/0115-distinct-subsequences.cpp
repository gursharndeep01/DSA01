class Solution {
public:

    int helper(string s, string t, int i , int j ){

        vector<double>dp(j+1, 0);
        dp[0] = 1;
        for(int n = 1; n <= i ; n++ ){
            for(int m = j; m >=1 ; m--){
                if(s[n-1] == t[m-1]){
                    dp[m] = dp[m-1] + dp[m];
                }
            }
        }
        return (int)dp[j];
    }

    int numDistinct(string s, string t) {
        int i = s.length();
        int j = t.length();
        return helper(s, t, i, j);
    }
};