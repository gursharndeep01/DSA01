class Solution {
public:
    int find(int a,vector<int> & vec){
        if(a!=vec[a]) vec[a]=find(vec[a],vec);
        return vec[a];
    }
    void uni(int i,int j,vector<int> & vec){
        int x=find(i,vec),y=find(j,vec);
        if(x!=y) vec[x]=y;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        vector<int> vec(m);
        for(int i=0;i<m;i++) vec[i]=i;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)continue;
                else if(isConnected[i][j]==1) uni(i,j,vec);
            }
        }
        for(int i=0;i<m;i++) vec[i]=find(i,vec);
        unordered_set<int> st(vec.begin(),vec.end());
        return st.size();
    }
};