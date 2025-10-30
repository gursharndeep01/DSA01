class Solution {
public:
    bool istrue(int left,int right,string & s){
        while(left<right){
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
    void arr(string &s,int i,vector<string> & res,vector<vector<string>>& ans){
        if(i==s.size()){
            ans.push_back(res);return;
        }
        for(int start=i;start<s.size();start++){
            if(istrue(i,start,s)){
                res.push_back(s.substr(i,start-i+1));
                arr(s,start+1,res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        vector<vector<string>> ans;
        arr(s,0,res,ans);
        return ans;
    }
};