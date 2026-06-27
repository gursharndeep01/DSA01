class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> vec (m+1,vector<int>(n+1,0));
        for(string & s:strs){
            int z=0,o=0;
            for(char c:s){
                if(c=='0') z++;
                else o++;
            }
            for(int i=m;i>=z;i--){
                for(int j=n;j>=o;j--) vec[i][j]=max(vec[i][j],vec[i-z][j-o]+1);
            }
        }
        return vec[m][n];
    }
};