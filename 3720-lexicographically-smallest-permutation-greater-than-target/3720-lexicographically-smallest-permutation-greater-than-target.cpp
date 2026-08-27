class Solution {
public:
    bool isans(int i, string& target,vector<int> &freq,string &ans){
        int n=target.size();
        if(i==n) return false;
        char c= target[i];
        if(freq[c-'a']>0){
            freq[c-'a']--;
            ans[i]=c;
            if( isans(i+1,target,freq,ans)) return true;
            freq[c-'a']++;
        }
        for(int j = c-'a'+1; j < 26; j++){
            if(freq[j] > 0){
                char smallest = 'a' + j;
                freq[j]--;
                ans[i]=smallest;
                int pos=i+1;
                for(int k=0;k<26;k++){
                    while(freq[k]>0){
                        ans[pos++]='a'+k;
                        freq[k]--;
                    }
                }
                return true;
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>  freq(26,0);
        for(char c: s) freq[c-'a']++;
        string ans(n,' ');
        bool possible=isans(0,target,freq,ans);
        return possible? ans:"";
    }
};