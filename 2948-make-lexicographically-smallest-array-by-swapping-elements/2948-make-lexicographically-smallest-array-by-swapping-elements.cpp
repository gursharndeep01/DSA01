class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n= nums.size();
        vector<pair<int,int>> sorted(n);
        for(int i=0;i<n;i++) sorted[i]={nums[i],i};
        sort(sorted.begin(),sorted.end());
        int i=0;
        vector<int> ans(n);
        while(i<n){
            vector<int> index;
            int j=i;
            while(j+1<n && sorted[j+1].first-sorted[j].first<=limit) j++;
            for(int k=i;k<=j;k++) index.push_back(sorted[k].second);
            sort(index.begin(),index.end());
            for(int k=0;k<index.size();k++) ans[index[k]]= sorted[i+k].first;
            i=j+1;
        }
        return ans;
    }
};