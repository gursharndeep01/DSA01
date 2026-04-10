class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &i: mpp){
            auto & vec= i.second;
            if(vec.size()<3) continue;
            for(int j=0;j<vec.size()-2;j++){
                int val= 2*(vec[2+j]-vec[j]);
                ans= min(ans,val);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};