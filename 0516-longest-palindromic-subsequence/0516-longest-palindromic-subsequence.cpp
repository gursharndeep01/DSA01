class Solution {
public:
    int rslt(string &s,int i,int j, vector<vector<int>> &vec){
        if(i>j) return 0;
        if(i==j) return 1;
        if(vec[i][j]!=-1) return vec[i][j];
        if(s[i]==s[j]){
            return vec[i][j]=2+ rslt(s,i+1,j-1,vec);
        } 
        else{
            return vec[i][j]= max(rslt(s,i+1,j,vec),rslt(s,i,j-1,vec));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> vec(n,vector<int>(n,-1));
        return rslt(s,0,n-1,vec);
    }
};