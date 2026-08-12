class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> map;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) map[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        int freq=0;
        if(!map.count(value)) return 0;
        auto l= lower_bound(map[value].begin(),map[value].end(),left);
        auto r= upper_bound(map[value].begin(),map[value].end(),right);
        return r-l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */