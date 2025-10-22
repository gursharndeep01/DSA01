class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        for(char & c : tasks) map[c]++;
        priority_queue<pair<int,char>> maxheap;
        for(auto & it: map) maxheap.push({it.second,it.first});
        int count=0,mainc=0;
        queue<pair<char,int>>  q;
        while(!maxheap.empty() || !q.empty()){
            mainc++;
            if(!q.empty() && q.front().second<=mainc){
                auto[ch,i]= q.front();
                q.pop();
                maxheap.push({map[ch],ch});
            }
            if(!maxheap.empty()){
                auto[freq,ch]=maxheap.top();
                maxheap.pop();
                map[ch]=--freq;
                if(freq>0) q.push({ch,mainc+n+1});
            }
        }
        return mainc;
    }
};