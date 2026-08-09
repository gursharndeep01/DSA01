class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> trustset;
        vector<int> count(n+1,
        0);
        for(auto & node: trust){
            trustset.insert(node[0]);
            count[node[1]]++;
        }
        for (int i=1;i<=n;i++){
            if(trustset.find(i) == trustset.end() && count[i]==n-1) return i; 
        }
        return -1;
    }
};