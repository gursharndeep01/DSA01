class Solution {
public:   
struct trienode{
    trienode* child[26];
    bool isend;
    trienode(){
        for(int i=0;i<26;i++) child[i]=NULL;
        isend=false;
    }
};
trienode* root;
       void make(string& word) {
        trienode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->child[i])
                cur->child[i] = new trienode();
            cur = cur->child[i];
        }
        cur->isend = true;
    }
    bool yes(string& word) {
        trienode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            cur = cur->child[i];
            if (!cur || !cur->isend)
                return false;
        }
        return true;
    }
    string longestWord(vector<string>& words) {
     root = new trienode();
        for (string& wrd : words) make(wrd);
        string ans = "";
        for (string& wrd : words) {
            if (yes(wrd)) {
                if (wrd.size() > ans.size() ||
                   (wrd.size() == ans.size() && wrd < ans))
                    ans = wrd;
            }
        }
        return ans;
    }
};