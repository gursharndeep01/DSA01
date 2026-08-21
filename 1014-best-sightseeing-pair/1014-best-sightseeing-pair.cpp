class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_val=values[0];
        int ans=0;
        for(int i=1;i<values.size();i++){
            ans=max(ans,max_val+values[i]-i);
            max_val=max(max_val,values[i]+i);
        }
        return ans;
    }
};