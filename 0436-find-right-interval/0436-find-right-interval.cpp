class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n= intervals.size();
        vector<int> rtrn(n,-1);
        vector<pair<int,int>> starts;
        for(int i = 0; i < n; i++){
            starts.push_back({intervals[i][0], i});
        }
        sort(starts.begin(), starts.end());
        for(int i=0;i<n;i++){
            int last=intervals[i][1];
            auto it = lower_bound(starts.begin(), starts.end(),make_pair(last, 0));
            if(it!=starts.end()) rtrn[i]=it->second;
        }
        return rtrn;
    }
};