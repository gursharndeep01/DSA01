class Solution {
public:
    int find(int x,vector<int> & parents){
        if(x!=parents[x]) parents[x]= find(parents[x],parents);
        return parents[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> parents(n+1);
        for(int i=1;i<=n;i++){
            parents[i]=i;
        }
        for(auto & edge: edges){
            int a = edge[0],b=edge[1];
            int parent_a= find(a,parents),parent_b=find(b,parents);
            if(parent_a==parent_b) return edge;
            parents[parent_a]= parent_b;
        }
        return edges[0];
    }
};