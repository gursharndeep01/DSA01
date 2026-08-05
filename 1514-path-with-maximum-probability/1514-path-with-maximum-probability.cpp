class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> max_heap;
        max_heap.push({1.0,start_node});
        vector<double> max_prob(n,0);
        max_prob[start_node]=1.0;
        while(!max_heap.empty()){
            auto it= max_heap.top();max_heap.pop();
            double curr_prob= it.first;
            int u= it.second;
            if(u==end_node) return curr_prob;
            if(curr_prob < max_prob[u]) continue;
            for(auto & neigh: adj[u]){
                int v= neigh.first;
                double prob_v= neigh.second;
                if(curr_prob*prob_v>max_prob[v]){
                    max_prob[v]= curr_prob*prob_v;
                    max_heap.push({max_prob[v],v});
                }
            }
        }
        return 0.0;
    }
};