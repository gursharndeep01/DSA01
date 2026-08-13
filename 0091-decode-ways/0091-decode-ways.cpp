class Solution {
public:
    int numDecodings(string s) {
        if (s[0]=='0') return 0;
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++){
            if(s[i-1]!='0') dp[i]+=dp[i-1];
            int number=stoi(s.substr(i-2,2));
            if (number>26 || number<10 ) continue;  
            else  dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};