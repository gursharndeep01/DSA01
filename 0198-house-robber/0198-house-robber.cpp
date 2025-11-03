class Solution {
public:
    int rob(vector<int>& nums) {
        int maxi=nums[0];
        if(nums.size()>=2) maxi=max(nums[1],maxi);
        if(nums.size()>2){
            nums[2]+=nums[0];
            maxi=max(nums[2],maxi);
            }
        for(int i=3;i<nums.size();i++){
            nums[i]+= max(nums[i-2],nums[i-3]);
            if(nums[i]>maxi) maxi=nums[i];
        }
        return maxi;
    }
};