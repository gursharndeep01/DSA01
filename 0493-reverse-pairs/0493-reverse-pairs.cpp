class Solution {
public:
    void merges(vector<int>& nums,int low,int mid,int high){
        vector<int> vec;
        int left=low,right=mid+1;
        while(left<=mid&& right<=high){
            if(nums[left]<=nums[right]) vec.push_back(nums[left++]);
            else vec.push_back(nums[right++]);
        }
        while(left<=mid) vec.push_back(nums[left++]);
        while(right<=high) vec.push_back(nums[right++]);
        for(int i=low;i<=high;i++) nums[i]=vec[i-low];
    }
    int merge(vector<int>&nums,int low,int high){
        if(low>=high) return 0;
        int mid= low +(high-low)/2;
        int cnt=0;
        cnt+= merge(nums,low,mid);
        cnt+= merge(nums,mid+1,high);
        int j= mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]> 2LL*nums[j]) j++;
            cnt+=(j-(mid+1));
        }
        merges(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return merge(nums,0,n-1);
    }
};