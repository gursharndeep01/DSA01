class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map <int,int> degree;
        for(auto &edge:edges){
            degree[edge[0]]++;degree[edge[1]]++;
        }
        for(auto &node: degree){
            int node_val=node.first;
            int ndegree= node.second;
            if(ndegree==edges.size()) return node_val;
        }
        return -1;
    }
};