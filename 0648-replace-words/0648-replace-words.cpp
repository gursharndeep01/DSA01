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
    string str;
    trienode* trie (vector<string>& dictionary){
        trienode* root= new trienode();
        for(string wrd : dictionary){
            trienode* crr= root;
            for(char c: wrd){
                int i= c-'a';
                if(!crr->child[i]) crr->child[i]= new trienode();
                crr=crr->child[i];
            }
            crr->isend =true;
        }
        return root;
    }
    string make(trienode* root,string wrd){
        trienode* crr= root;
        string s;
        for(char c: wrd){
            int i= c-'a';
            if(!crr->child[i]) return wrd;
            s.push_back(c);
            crr=crr->child[i]; 
            if(crr->isend) return s; 
        }
        return wrd;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        trienode* root= trie(dictionary);
        string wrd, rtrn;
        int i=0;
        while (i < sentence.size()) {
            while (i < sentence.size() && sentence[i] == ' ')
                i++;
            wrd.clear();
            while (i < sentence.size() && sentence[i] != ' ') {
                wrd.push_back(sentence[i]);
                i++; 
            }

            if (!wrd.empty()) {
                rtrn += make(root, wrd);
                rtrn.push_back(' ');
            }
        } 
        rtrn.pop_back();
        return rtrn;
    }
};