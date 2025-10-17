class Solution {
public:
    string reorganizeString(string s) {
                priority_queue<pair<int,char>> maxheap;
        unordered_map<char,int> mpp;
        for(char & ch:s) mpp[ch]++;
        char topu='$',curr,curr1;
        int val;
        for(auto & a: mpp) maxheap.push({a.second,a.first});
        string ss="";
        while(!maxheap.empty()){
            auto top=maxheap.top();maxheap.pop();
            curr=top.second;
            if(curr==topu && !maxheap.empty()){
                auto ntop=maxheap.top();maxheap.pop();
                curr1=ntop.second;
                ss+=curr1;
                val= ntop.first;
                val--;
                topu=curr1;
                if(val>0)maxheap.push({val,curr1});
                maxheap.push(top);
            }
            else{
                ss+=curr;
                val=top.first;val--;
                topu=curr;
                if(val>0)maxheap.push({val,curr});
            }
        }
        if(ss.size()!=s.size()) return "";
        for(int i=0;i<ss.size();i++){
            if(i>0 && ss[i]==ss[i-1]) return "";
        }
        return ss;
    }
};