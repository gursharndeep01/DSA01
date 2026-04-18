class Solution {
public: 
    void reverse(string &s, int i,int j){
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
    string reverseWords(string s) {
        int size= s.size();
        reverse(s,0,size-1);
        int i=0;
        while(i<size){
            if(s[i]==' ') {i++;continue;}
            int j=i;
            while(i<size && s[i]!=' ')i++;
            reverse(s,j,i-1);
        }
        int idx=0;
        i=0;
        while(i<size){
            if(s[i]==' ') {i++;continue;}
            if(idx!=0) s[idx++]=' ';
            while(i<size && s[i]!=' ') s[idx++]=s[i++];
        }
        s.resize(idx);
        return s;
    }
};