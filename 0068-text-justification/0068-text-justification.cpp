class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vec;
        int i=0,n=words.size();
        while(i<n){
            int j=i,len=0;
            while(j<n && (len+words[j].size()+(j-i))<=maxWidth){
                len+=words[j].size();
                j++;
            }
            string s;
            int gap=j-i-1;
            if(j==n || gap==0){
                for (int k=i;k<j;k++){
                    s+=words[k];
                    if(k<j-1) s+=' ';
                }
                s+= string(maxWidth-s.size(),' ');
            }
            else {
                int space=(maxWidth-len)/gap;
                int left=(maxWidth-len)%gap;
                for(int a=i;a<j;a++){
                s+=words[a];
                if(a<j-1) {
                    if(left>0){
                    s+= string(space+1, ' ');
                    left--;
                }
                else s +=string(space, ' ');
                }
                }
            }
            vec.push_back(s);
            i=j;
        }
        return vec;
    }
};