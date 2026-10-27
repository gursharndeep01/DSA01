class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> vec(m, string(n,'#'));
        for(int i=0;i<m;i++) vec[i][n-1]='.';
        for(int i=0;i<n;i++) vec[0][i]='.';
        return vec;
    }
};