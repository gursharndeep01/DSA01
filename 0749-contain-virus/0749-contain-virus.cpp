class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m= isInfected.size(),n=isInfected[0].size();
        vector<int> drxn={0,1,0,-1,0};
        int totalwalls=0;
        while(true){
            vector<vector<int>> visited(m,vector<int> (n,0));
            vector<vector<pair<int,int>>> tisland;
            vector<set<pair<int,int>>> twilleffect;
            vector<int> wallno;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(isInfected[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>> island;
                    set<pair<int,int>> willeffect;
                    int wall=0;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j]=1;
                    while(!q.empty()){
                        auto[x,y]=q.front();
                        q.pop();
                        island.push_back({x,y});
                        for(int k=0;k<4;k++){
                            int xx=x+drxn[k];
                            int yy=y+drxn[k+1];
                            if(xx<0 || yy <0 || xx>=m || yy>=n) continue;
                            if(isInfected[xx][yy]==1 && !visited[xx][yy]){
                                q.push({xx,yy});
                                visited[xx][yy]=1;
                            }
                            else if(isInfected[xx][yy]==0 ){
                                willeffect.insert({xx,yy});
                                wall++;
                            }
                        }
                    }
                    tisland.push_back(island);
                    twilleffect.push_back(willeffect);
                    wallno.push_back(wall);
                }
            }
        }
        int indx=-1, maxeffect=0;
        for(int i=0;i<twilleffect.size();i++){
            if(twilleffect[i].size()>maxeffect){
                indx=i;
                maxeffect=twilleffect[i].size();
            }
        }
        if(indx==-1) break;
        totalwalls+=wallno[indx];
        for(auto &it: tisland[indx]) isInfected[it.first][it.second]=-1;
        for(int i=0;i<twilleffect.size();i++){
            if (i==indx) continue;
            for(auto &it: twilleffect[i]) isInfected[it.first][it.second]=1;
        }
    }
    return totalwalls;
    }
};