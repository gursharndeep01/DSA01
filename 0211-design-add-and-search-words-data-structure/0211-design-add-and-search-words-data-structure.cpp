class WordDictionary {
public:
    struct trienode {
        bool islast;
        trienode* child[26];
        trienode(){
            islast= false;
            for(int i=0;i< 26;i++)  child[i]=NULL;
        }
    };
    trienode* root;
    WordDictionary() {
        root = new trienode();
    }
    
    void addWord(string word) {
        trienode* crr=root;
        for(char c:word){
            int i= c -'a';
            if(!crr->child[i]) crr-> child[i]= new trienode();
            crr=crr->child[i];
        }
        crr->islast = true;
    }
    bool help(string & word,trienode* crr,int x){
        if (x == word.size()) return crr->islast;
        if (word[x]=='.'){
            for(int i=0;i<26;i++){
                if (crr->child[i] && help(word, crr->child[i], x + 1))
                return true;
            }
            return false;
        }
        int i= word[x] -'a';
        if(!crr->child[i]) return false;
        return help( word,crr->child[i],x+1);
    }
    bool search(string word) {
        return help( word,root,0);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */