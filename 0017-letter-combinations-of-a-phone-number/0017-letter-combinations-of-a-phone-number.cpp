class Solution {
public:
    vector<string> str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void letter(vector<string> &vec,string &st,string digits,int i){
        if(st.size()==digits.size()){
            vec.push_back(st);
            return;
        }
        int a=digits[i]-'0';
        for(int j=0;j<str[a].size();j++){
            st.push_back(str[a][j]);
            letter(vec,st,digits,i+1);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string st="";
        vector<string> vec;
        int i=0;
        letter(vec,st,digits,i);
        return vec;
    }
};