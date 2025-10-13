class Solution {
public:
    char find(char c ,unordered_map<char,char> &parent){
        if(parent[c]!=c) parent[c]=find(parent[c],parent);
        return parent[c];
    }
    void uni(string s,unordered_map<char,char> &parent){
        char x=find(s[0],parent);
        char y=find(s[3],parent);
        if(x!=y) parent[x]=y;
    }
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,char> parent;
        for(char c='a';c<='z';c++) parent[c]=c;
        unordered_set<string> tochk;
        for( string &s: equations){
            if(s[1]=='!') tochk.insert(s);
            else uni(s,parent);
        }
        for (auto &[v1,v2]:parent) parent[v1]=find(v1,parent);
        for(auto &s: tochk){
        char x=parent[s[0]];
        char y=parent[s[3]];
        if(x==y) return false;
        }
        return true;
    }
};