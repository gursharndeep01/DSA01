class Solution {
public:
struct cmp {
    bool operator() (vector<int> &a,vector<int> & b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
};
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp());
        int last = intervals[0][1];
        int remove=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<last) remove++;
            else last=intervals[i][1];
        }
        return remove ;
    }
};