class Solution {
public:
    int scoreOfParentheses(string s) {
        int sum=0,count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') count++;
            else {
                count--;
                if(s[i-1]=='(') sum+= 1<<count;
            }
        }
        return sum;
    }
};