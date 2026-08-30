class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        for(int k=0;k<n;k++){
            if(nums[i]>nums[k]) i=k;
            else if(nums[j]<nums[k]) j=k;
        }
        int front= max(i,j)+1;
        int back= n- min(i,j);
        int mid= min(i,j)+1 + n- max(i,j);
        return min({front,back,mid});
    }
};