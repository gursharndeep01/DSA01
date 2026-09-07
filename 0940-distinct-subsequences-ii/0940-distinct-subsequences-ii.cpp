class Solution {
public:
    int distinctSubseqII(string s) {
        int n= s.size();
        vector<long long> end(n+1);
        end[0]=1;
        vector<int> last(26,-1);
        int MOD= 1e9+7;
        int ans=0;
        for(int i=1;i<=n;i++){
            int c= s[i-1]-'a';
            end[i]=(2*end[i-1])% MOD;
            if(last[c]!=-1){
                end[i]= (end[i]-end[last[c]-1]+MOD) %MOD;
            }
            last[c]=i;
        }
        return (int)( (end[n]-1+MOD) %MOD); 
    }
};