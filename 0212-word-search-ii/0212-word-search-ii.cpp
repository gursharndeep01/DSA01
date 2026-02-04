class Solution {
public:
struct TrieNode {
        TrieNode* child[26];
        string word; 
        TrieNode() {
            for (int i = 0; i < 26; i++) child[i] = NULL;
            word = "";
        }
    };
    vector<string> vec;
    int m, n;
     TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* cur = root;
            for (char c : w) {
                int i = c - 'a';
                if (!cur->child[i])
                    cur->child[i] = new TrieNode();
                cur = cur->child[i];
            }
            cur->word = w; 
        }
        return root;
    }
     void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur) {
        char cc = board[r][c];
        if (cc == '0' || !cur->child[cc - 'a']) return;
        cur = cur->child[cc - 'a'];
        if (cur->word != "") {
            vec.push_back(cur->word);
            cur->word = "";
        }
        board[r][c] = '0';  
        if (r > 0) dfs(board, r - 1, c, cur);
        if (c > 0) dfs(board, r, c - 1, cur);
        if (r < m - 1) dfs(board, r + 1, c, cur);
        if (c < n - 1) dfs(board, r, c + 1, cur);
        board[r][c] = cc;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         m = board.size();
        n = board[0].size();

        TrieNode* root = buildTrie(words);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        return vec;
    }
};