class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,ll=0,r=nums.size()-1,rr=nums.size()-1;
        int a=-1,aa=-1;
        while(l<=r){
            int mid = l +((r-l)>>1);
            if(nums[mid]==target){
                a=mid;
                r=mid-1;
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        while(ll<=rr){
            int mid = ll +((rr-ll)>>1);
            if(nums[mid]==target){
                aa=mid;
                ll=mid+1;
            }
            else if(nums[mid]<target) ll=mid+1;
            else rr=mid-1;
        }
        return {a,aa};
    }
};