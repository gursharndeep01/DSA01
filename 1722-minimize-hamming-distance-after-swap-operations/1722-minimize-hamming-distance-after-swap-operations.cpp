class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto& e : allowedSwaps) {
            unite(e[0], e[1]);
        }
        unordered_map<int, unordered_map<int,int>> mpp;
        for (int i = 0; i < n; i++) {
            int p = find(i);
            mpp[p][source[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int p = find(i);
            if (mpp[p][target[i]] > 0) {
                mpp[p][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};