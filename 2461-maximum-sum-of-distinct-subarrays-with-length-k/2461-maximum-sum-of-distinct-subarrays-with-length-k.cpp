class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long no=0,sum=0;
        unordered_map<int,int> mpp;
        int j=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mpp[nums[i]]++;

            while(mpp[nums[i]]>1 || (i-j+1) >k){
                mpp[nums[j]]--;
                sum-=nums[j];
                if(mpp[nums[j]]==0) mpp.erase(nums[j]);
                j++;
            }

            if((i-j+1)==k){
                no=max(no,sum);
            }
        }
        return no;
    }
};