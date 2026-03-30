class Solution {
public:
    bool checkStrings(string s1, string s2) {
      vector <int> vece(26,0) , veco(26,0);
        for (int i=0;i< s1.size();i++){
            if(i%2==0){
                vece[s1[i]-'a']++;
                vece[s2[i]-'a'] --;
            }
            else {
                veco[s1[i]-'a']++;
                veco[s2[i]-'a']--;
            }
        }
        for (int i=0;i<26;i++){
            if (vece[i]!=0) return false;
            if (veco[i]!=0) return false;
        }
        return true;
    }
};