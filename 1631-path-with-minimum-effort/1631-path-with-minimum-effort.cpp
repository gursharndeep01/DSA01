class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size(),m=heights[0].size();
        vector<vector<int>> effort_dp(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
        vector<int> direction={0,-1,0,1,0};
        minheap.push({0,0,0});
        effort_dp[0][0]=0;
        while(!minheap.empty()){
            auto it= minheap.top();
            minheap.pop();
            int effort= it[0], i=it[1],j=it[2];
            if( i==n-1 && j==m-1) return effort;
            for(int k=0;k<4;k++){
                int newi= i+direction[k];
                int newj= j+direction[k+1];
                if (newi<0 || newj<0 || newi>=n || newj>=m) continue;
                int neweffort= max(effort,abs(heights[i][j]-heights[newi][newj]));
                if(neweffort < effort_dp[newi][newj]) {
                    effort_dp[newi][newj] = neweffort;
                    minheap.push({neweffort,newi,newj});
                }
            }
        }
        return 0;
    }
};