class Solution {
public:
    bool isNumber(string s) {
        bool digitp=false, dotp=false , eEp=false;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])) digitp=true;
            else if(s[i]=='+' || s[i]=='-'){
                if(i!=0 && !(s[i-1]=='e'|| s[i-1]=='E' )) return false;
            }
            else if(s[i]=='.'){
                if(eEp || dotp) return false;
                dotp=true;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(eEp || !digitp) return false;
                eEp=true;
                digitp=false;
            }
            else return false;
        }
        return digitp;
    }
};