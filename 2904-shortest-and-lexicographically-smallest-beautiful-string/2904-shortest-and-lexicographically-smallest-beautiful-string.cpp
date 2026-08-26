class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n= s.size();
        int left=0,right=0;
        string best="";
        int count=0;
        while(right<n){
            if(s[right]=='1') count++;
            while(left<right && count>k){
                if(s[left]=='1')count--;
                left++;
            }
            
            if(count==k) {
                while(left<right && s[left]=='0') left++;
                string subs= s.substr(left,right-left+1);
                if(best.empty() || subs.size() < best.size() ||(subs.size()==best.size() && subs<best )) best= subs;
            }
            right++;
        }
        return best;
    }
};