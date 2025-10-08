class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[nums.size()-1];
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1,right=nums.size()-1;
            while(left<right){
                long long sum=nums[i]+nums[left]+nums[right];
                if(abs(sum-target)<abs(closest-target)){
                    closest=sum;
                }
                if(sum<target ) left++;
                else right--;
            }
        }
        return closest;
    }
};