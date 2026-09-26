class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string> map;
        for(int i=0;i<knowledge.size();i++) map[knowledge[i][0]]=knowledge[i][1];
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='('){
                ans+=s[i];
                continue;
            }
            int j=i+1;
            while(j<n && s[j]!=')') j++;
            string ss= s.substr(i+1,j-i-1);
            if(map.count(ss)) ans+=map[ss];
            else ans+='?';
            i=j;
        }
        return ans;
    }
};