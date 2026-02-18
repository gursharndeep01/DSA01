class Solution {
public: 
    void rec(int n,string &s,int o, int c,vector<string> &vec){
        if(s.size()==(2*n)){
            vec.push_back(s);
            return;
        }
        if(o<n){
            s+='(';
            rec(n,s,o+1,c,vec);
            s.pop_back();
        }
        if(c<o){
            s+=')';
            rec(n,s,o,c+1,vec);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string s="";
        rec(n,s,0,0,vec);
        return vec;
    }
};