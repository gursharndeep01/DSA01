class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> vec;
        for (string &s:queries){
            for(string &ss :dictionary){
                int edits=0, i=0;
                for(i;i<ss.size() ;i++){
                    if(s[i]==ss[i]) continue;
                    if(s[i]!=ss[i] && edits!=2) edits++;
                    else break; 
                }
                if(i==s.size() && edits<3) {
                    vec.push_back(s);break;}
            }
        }
        return vec;
    }
};