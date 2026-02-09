class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> vec(n,INT_MAX);
        vec[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> tempu =vec;
            for(auto & f: flights){
                if(vec[f[0]] != INT_MAX){
                    tempu[f[1]]=min(tempu[f[1]],vec[f[0]]+f[2]);
                }
            }
            vec=tempu;
        }
        return vec[dst]==INT_MAX? -1:vec[dst];
    }
};