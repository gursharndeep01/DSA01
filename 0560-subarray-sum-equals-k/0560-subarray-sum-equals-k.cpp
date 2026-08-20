class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int prefix=0;
        for(int num:nums){
            prefix+=num;
            if(mpp.count(prefix-k)) ans+=mpp[prefix-k];
            mpp[prefix]++;
        }
        return ans;
    }
};