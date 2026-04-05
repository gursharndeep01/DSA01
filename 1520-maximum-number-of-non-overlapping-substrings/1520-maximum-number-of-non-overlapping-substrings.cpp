class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> left(26,-1),right(26,-1);
        int n=s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (left[c] == -1) left[c] = i;
            right[c] = i;
        }
        vector<pair<int,int>> vec;
        for(int i=0;i<26;i++){
            if(left[i]==-1) continue;
            int start=left[i],end=right[i];
            bool istrue=true;
            for(int j=start;j<end;j++){
                if(left[s[j]-'a']<start){
                    istrue=false;break;
                }
                end=max(end,right[s[j]-'a']);
            }
            if(istrue) vec.push_back({start,end});
        }
        sort(vec.begin(),vec.end(),[](auto & a,auto &b){
            return a.second<b.second;
        });
        vector<string> vecc;
        int end=-1;
        for(auto &i: vec){
            if(i.first > end){
                vecc.push_back(s.substr(i.first,i.second-i.first+1));
                end=i.second;
            }
        }
        return vecc;
    }
};