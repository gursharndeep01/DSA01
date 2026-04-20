class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_set<int> set;
        int maxi=0;
        for(int i=0;i<colors.size();i++){
            if(set.count(colors[i])) continue;
            set.insert(colors[i]);
            for(int j=i+1;j<colors.size();j++){
                if(colors[i]==colors[j]) continue;
                maxi=max(maxi,j-i);
            }
        }
        return maxi;
    }
};