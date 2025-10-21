class Solution {
public:
    vector<int> partitionLabels(string s) {
        bool adad=true;
        unordered_map<char,int> main;
        for(char & c:s){
            main[c]++;
            if(main[c]>1) adad=false;
        }
        if(adad) return vector<int> (s.size(),1);
        unordered_map<char,int> ini;
        vector<int> vec;
        int last=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            ini[c]++;
            if(ini[c]==main[c]){
                ini.erase(c);
                if(ini.size()==0){
                    vec.push_back(i-last+1);
                    last=i+1;
                }
            }
        }
        return vec;
    }
};