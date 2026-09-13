class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> a,b;
        int n=img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]) a.push_back({i,j});
                if(img2[i][j]) b.push_back({i,j});
            }
        }
        int ans=0;
        map<pair<int,int>,int> mpp;
        for(pair<int,int> &p:a){
            for(auto &q:b){
                ans=max(ans,++mpp[{p.first-q.first,p.second-q.second}]);
            }
        }
        return ans;
    }
};