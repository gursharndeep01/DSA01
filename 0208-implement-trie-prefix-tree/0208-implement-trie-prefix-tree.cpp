class trienode{
public:
    char data;
    trienode* children[26];
    bool isend;
    trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++) children[i]= NULL;
        isend=false;
    }
};
class Trie {
public:    
    trienode* root;
    Trie() {
        root =new trienode('0');
    }
    void inserthelp(trienode* root,string word){
        if(word.size()==0) {
            root->isend =true;
            return;
        }
        int i= word[0]-'a';
        trienode* child;
        if(root->children[i]!= NULL){
            child= root->children[i];
        }
        else{
            child =new trienode(word[0]);
            root->children[i]=child;
        }
        inserthelp(child,word.substr(1));
    }
    void insert(string word) {
        inserthelp(root,word);
    }
    bool searchelp(trienode* root,string word){
        if(word.size()==0) return root->isend;
        int i= word[0]-'a';
        trienode* child;
        if(root->children[i]!= NULL){
            child= root->children[i];
        }
        else return false;
        return searchelp(child,word.substr(1));
    }
    bool search(string word) {
        return searchelp(root,word);
    }
    
    bool start(trienode* root,string word){
        if(word.size()==0) return true;
        int i= word[0]-'a';
        trienode* child;
        if(root->children[i]!= NULL){
            child= root->children[i];
        }
        else return false;
        return start(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return start(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */