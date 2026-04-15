class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);cuts.push_back(n);
        int m=cuts.size();
        vector<vector<int>> vec(m,vector<int>(m,0));
        for(int i=m-2;i>=1;i--){
            for(int j=1;j<=m-2;j++){
                if(i>j) continue;
                int mini= INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost = cuts[j+1]-cuts[i-1]+ vec[i][k-1]+vec[k+1][j];
                    mini=min(mini,cost);
                }
                vec[i][j]= mini;
            }
        }
        return vec[1][m-2];
    }
};