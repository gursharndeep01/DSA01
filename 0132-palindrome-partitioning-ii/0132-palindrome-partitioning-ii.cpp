class Solution {
public:
    int minCut(string s) {
                int lgh=s.size();
        vector<vector<bool>> tru(lgh,vector<bool>(lgh,false));
        for(int k=0;k<lgh;k++){
            int i=0;
            for(int j=k;j<lgh;j++){
                if(k==0) tru[i][j]=true;
                else if(k==1) tru[i][j]=(s[i]==s[j]);
                else tru[i][j]=((s[i]==s[j]) && (tru[i+1][j-1]));
                i++;
            }
        }
        vector<int> vec(lgh,0);
        for(int i=0;i<lgh;i++){
            if(tru[0][i]) vec[i]=0;
            else {
                int mini=INT_MAX;
                for(int j=1;j<=i;j++){
                    if(tru[j][i]){
                        mini=min(mini,vec[j-1]+1);
                    }
                }
                vec[i]=mini;
            }
        }
        return vec[lgh-1];
    }
};