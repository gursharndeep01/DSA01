class Solution {
public:
    void solve(unordered_map<string, vector<string>> &adj,
               vector<vector<string>> &vada,
               vector<string> &ans,
               string beginWord,
               string word) {
        ans.push_back(word);
        if (word == beginWord) {
            reverse(ans.begin(), ans.end());
            vada.push_back(ans);
            reverse(ans.begin(), ans.end());
            ans.pop_back();
            return;
        }
        for (string prev : adj[word]) {
            solve(adj, vada, ans, beginWord, prev);
        }
        ans.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        if (!list.count(endWord)) return {};
        unordered_map<string, int> visited;
        unordered_map<string, vector<string>> adj;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 0;
        int len = beginWord.size();
        bool found = false;
        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;
            while (sz--) {
                string word = q.front(); q.pop();
                int dis = visited[word];
                for (int i = 0; i < len; i++) {
                    string temp = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (temp[i] == c) continue;
                        temp[i] = c;
                        if (!list.count(temp)) continue;
                        if (!visited.count(temp)) {
                            visited[temp] = dis + 1;
                            q.push(temp);
                            levelVisited.insert(temp);
                        }
                        if (visited[temp] == dis + 1)
                            adj[temp].push_back(word);
                        if (temp == endWord)
                            found = true;
                    }
                }
            }
            for (auto &x : levelVisited) list.erase(x);
        }
        if (!visited.count(endWord)) return {};
        vector<vector<string>> vada;
        vector<string> ans;
        solve(adj, vada, ans, beginWord, endWord);
        return vada;
    }
};
