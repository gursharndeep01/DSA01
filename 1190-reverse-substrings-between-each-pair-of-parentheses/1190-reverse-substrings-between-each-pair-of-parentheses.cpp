class Solution {
public:
    string reverseParentheses(string s) {
        int n= s.size();
        vector<int> vec(n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(s[i]=='(') stk.push(i);
            else if(s[i]==')'){
                int j= stk.top();stk.pop();
                vec[i]=j;vec[j]=i;
            }
        }
        string ans="";
        for(int i=0,d=1;i<n;i+=d){
            if(s[i]=='(' || s[i]==')'){
                i=vec[i];
                d= -d;
            }
            else ans+=s[i];
        }
        return ans;
    }
};