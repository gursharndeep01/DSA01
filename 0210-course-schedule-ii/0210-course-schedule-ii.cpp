class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for( auto & pair:prerequisites){
            int v=pair[1],u=pair[0];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        vector<int> courses;
        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int v=q.front();q.pop();
            courses.push_back(v);
            for(int u :adj[v]) if(--indegree[u]==0) q.push(u);
        }
        return courses.size()==numCourses?courses:vector<int> {};
    }
};