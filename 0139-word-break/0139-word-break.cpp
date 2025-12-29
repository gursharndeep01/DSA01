class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
unordered_set<string> set;
        for(string str : wordDict) set.insert(str);
        vector<bool> tru(s.size()+1,false);
        tru[0]=true;
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<i;j++){
                string st=s.substr(j,i-j);
                if(set.count(st) && tru[j]){
                    tru[i]=true;
                    break;
                }
            }
        }
        return tru[s.size()];
    }
};