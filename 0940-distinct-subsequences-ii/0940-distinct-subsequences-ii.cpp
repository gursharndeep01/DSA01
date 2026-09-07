class Solution {
public:
    int distinctSubseqII(string s) {
        int n= s.size();
        vector<int> end(n,1);
        int MOD= 1e9+7;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(s[i]==s[j]) continue;
                end[i]=(end[i]+end[j]) % MOD;
            }
            ans= (ans+end[i]) %MOD;
        }
        return ans; 
    }
};