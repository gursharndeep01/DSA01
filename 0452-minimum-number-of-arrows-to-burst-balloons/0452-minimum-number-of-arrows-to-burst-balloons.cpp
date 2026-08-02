class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });
        int arrow=1;
        int arrowpos=points[0][1];
        for(auto & pairs:points){
            if(arrowpos>=pairs[0]) continue;
            arrowpos=pairs[1];
            arrow++;
        }
        return arrow;
    }
};