class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return {};
        vector<int> vec;
        vector<int> fre(26,0);
        for(char c: p) fre[c-'a']++;
        int l=0,r=0,cnt=p.size();
        while(r<s.size()){
            if(fre[s[r]-'a']>0) cnt--;
            fre[s[r]-'a']--;
            r++;
            if((r-l)==p.size()){
                if(cnt==0) vec.push_back(l);
                if (fre[s[l] - 'a'] >= 0) cnt++;
                fre[s[l] - 'a']++;
                l++;
            }
        }
        return vec;
    }
};