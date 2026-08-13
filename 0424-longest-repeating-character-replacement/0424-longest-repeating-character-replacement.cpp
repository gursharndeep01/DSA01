class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0 || s.size()==1) return s.size();
        int left=0,right=0;
        vector<int> freq(26,0);
        int maxfreq=0;
        int ans=0;
        while(right<s.size()){
            freq[s[right]-'A']++;
            maxfreq=max(maxfreq,freq[s[right]-'A']);
            if(right-left+1 - maxfreq <=k) ans=max(ans,right-left+1);
            else {
                while(right-left+1 - maxfreq > k){
                    freq[s[left]-'A']--;
                    left++;
                }
            }
            right++;
        }
        return ans;
    }
};