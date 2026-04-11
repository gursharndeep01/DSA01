class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,pair<int,int>> mpp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(nums[i])){
                auto &[last,lastlast]=mpp[nums[i]];
                if(lastlast!=-1){
                    int tempu= 2*(i-lastlast);
                    ans=min(ans,tempu);
                }
                lastlast=last; last=i;
            }
            else mpp[nums[i]]={i,-1};
        }
        return ans==INT_MAX?-1:ans;
    }
};