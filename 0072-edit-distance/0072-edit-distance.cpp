class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> vec(word1.size()+1,vector<int> (word2.size()+1,0));
        for(int i=1;i<=word1.size();i++){
            vec[i][0]=i;
        }
        for(int i=1;i<=word2.size();i++){
            vec[0][i]=i;
        }
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]) vec[i][j]=vec[i-1][j-1];
                else {
                    vec[i][j]=1+min({vec[i-1][j-1],vec[i-1][j],vec[i][j-1]});
                }
            }
        }
        return vec[word1.size()][word2.size()];
    }
};