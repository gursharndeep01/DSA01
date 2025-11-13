class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1=text1.size(), s2=text2.size();
        if(text1==text2) return s1;
        vector<vector<int>> vec(s1+1,vector<int>(s2+1,0));
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]) vec[i][j]=1+vec[i-1][j-1];
                else vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
            }
        }
        return vec[s1][s2];
    }
};