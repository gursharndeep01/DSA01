class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        int l=0;
        int freq=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while((1LL*nums[r]*(r-l+1)-sum)>k){
                sum-=nums[l];
                l++;
            }
            freq=max(freq,r+1-l);
        }
        return freq;
    }
};