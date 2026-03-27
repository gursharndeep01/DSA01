class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        int n= path.size();
        string s="";
        for(int i=0;i<=n;i++){
            if(i==n ||path[i]=='/'){
                if(s=="..") {
                    if(!vec.empty()) vec.pop_back();
                }
                else if(s!="" && s!=".") vec.push_back(s);
                s="";
            }
            else s+=path[i];
        }
        string ss="";
        for( auto &it: vec) ss+="/"+ it;
        return ss.empty() ? "/" : ss;
    }
};