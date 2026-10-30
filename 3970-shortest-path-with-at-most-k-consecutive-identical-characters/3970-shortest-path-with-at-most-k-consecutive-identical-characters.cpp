class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, 1e18));
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();

            if (u == n - 1) return d;
            if (d > dist[u][cur]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                int nxt = (labels[v] != labels[u]) ? 1 : cur + 1;

                if (nxt <= k) {
                    long long nd = d + w;
                    if (nd < dist[v][nxt]) {
                        dist[v][nxt] = nd;
                        pq.push({nd, v, nxt});
                    }
                }
            }
        }

        return -1;
    }
};