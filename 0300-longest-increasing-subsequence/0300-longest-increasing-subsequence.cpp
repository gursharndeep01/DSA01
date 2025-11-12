class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
                vector<int> vec(nums.size(),0);
        int maxi=0;
        vec[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    vec[i]=max(vec[i],vec[j]+1);
                }
            }
            if(vec[i]==0) vec[i]=1;
            maxi=max(maxi,vec[i]);
        }
        return maxi;
    }
};