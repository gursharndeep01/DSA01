class Solution {
public:
    unordered_set<string> st;
    void call(int idx,int open,int l_rem,int r_rem,string &s,string &temp){
        if(idx==s.size()){
            if(r_rem==0 && l_rem==0) st.insert(temp);
            return;
        }
        char c=s[idx];
        if(c=='('){
            if(l_rem>0) call(idx+1,open,l_rem-1,r_rem,s,temp);
            temp+='(';
            call(idx+1,open+1,l_rem,r_rem,s,temp);
            temp.pop_back();
        }
        else if(c==')'){
            if(r_rem>0) call(idx+1,open,l_rem,r_rem-1,s,temp);
            if(open>0){
                temp+=')';
                call(idx+1,open-1,l_rem,r_rem,s,temp);
                temp.pop_back();
            }
        }
        else{
            temp+=c;
            call(idx+1,open,l_rem,r_rem,s,temp);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int l_rem=0,r_rem=0;
        for(char c: s){
            if(c=='(') l_rem++;
            else if(c==')'){
                if(l_rem>0) l_rem--;
                else r_rem++;
            }
        }
        string temp="";
        call(0,0,l_rem,r_rem,s,temp);
        vector<string> vec;
        vec.insert(vec.end(),st.begin(),st.end());
        return vec;
    }
};