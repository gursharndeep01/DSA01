class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int tsum=0;
        for(int num:nums) tsum+=num;
        if(tsum<target) return 0;
        int right=0,left=0;
        long long sum=0;
        int minsize=INT_MAX;
        while(right<nums.size()){
            while(sum>=target){
                minsize=min(minsize,right-left);
                sum-=(long long)nums[left];
                left++;
            }
            sum+=nums[right];
            right++;
        }
        if(sum>=target) minsize=min(minsize,right-left);
        while(left<nums.size()){
            sum-=(long long)nums[left];
            left++;
            if(sum>=target) minsize=min(minsize,right-left);
        }
        return minsize;
    }
};