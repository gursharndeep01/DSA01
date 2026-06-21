class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> vec(n,0);
        for(int i=0;i<n;i++){
            if(vec[i]!=0) continue;
            vec[i]=1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int k= q.front();q.pop();
                for(int &nn: graph[k]){
                    if(vec[k]==vec[nn]) return false;
                    if(vec[nn]==0){
                        vec[nn]= -1*vec[k];
                        q.push(nn);
                    }
                }
            }
        }
        return true;
    }
};