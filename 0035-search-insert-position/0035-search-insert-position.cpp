class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size();
        while(left<right){
            int mid = (left+right)>>1;
            if(target==nums[mid]) return mid;
            else if(target<nums[mid]) right=mid;
            else left=mid+1;
        }
        return left;
    }
};