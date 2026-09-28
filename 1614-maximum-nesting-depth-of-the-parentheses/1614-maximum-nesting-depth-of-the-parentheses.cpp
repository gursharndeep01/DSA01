class Solution {
public:
    int maxDepth(string s) {
        int ans=0, tempans=0;
        stack<char> st;
        for(char c: s){
            if(c=='('){
                st.push(c);
                tempans++;
            }
            else if(c==')'){
                st.pop();
                ans=max(ans,tempans);
                tempans=st.size();
            }
        }
        return ans;
    }
};