class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n= nums.size();
        int start=-1,end=-2;
        int max_val=INT_MIN, min_val= INT_MAX;
        for(int i=0;i<n;i++){
            max_val=max(max_val,nums[i]);
            if(nums[i]<max_val) end=i;
        }
        for(int i=n-1;i>=0;i--){
            min_val=min(min_val,nums[i]);
            if(nums[i]>min_val) start=i;
        }
        return end-start+1;
    }
};