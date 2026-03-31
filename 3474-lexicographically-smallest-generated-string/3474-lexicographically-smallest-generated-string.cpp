class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        string s(n+m-1,'#');
        vector<bool> vec(n + m - 1, false); 
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=0;j<m;j++){
                    if(s[i+j]=='#'|| s[i+j]==str2[j]) {
                        s[i+j]=str2[j];
                        vec[i+j] = true;
                    }
                    else return "";
                }
            }
        }
        for(int i=0;i<m+n-1;i++){
            if(s[i]=='#') s[i]='a';
        }
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                bool ismatch=true;
                for(int j=0;j<m;j++){
                    if(str2[j]!=s[i+j]) {
                        ismatch=false;
                        break;
                    }
                }
                if(ismatch){
                    bool update= false;
                    for(int j=m-1;j>=0;j--){
                        if(!vec[i+j] && s[i+j] != 'z'){
                            s[j+i]++;
                            update=true;
                            break;
                        }
                    }
                    if(!update) return "";
                }
            }
        }
        return s;
    }
};