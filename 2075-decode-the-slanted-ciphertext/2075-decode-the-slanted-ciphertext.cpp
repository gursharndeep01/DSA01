class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows==1) return encodedText;
        int size=encodedText.size();
        string s="";
        int clm= size/rows, ni=clm+1;
        for(int i=0;i<clm;i++){
            for(int j=i;j<size;j+=ni) s+=encodedText[j];
        }
        while(!s.empty() && s.back()==' ') s.pop_back();
        return s;
    }
};