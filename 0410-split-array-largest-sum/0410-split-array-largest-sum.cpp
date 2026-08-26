class Solution {
public:
    bool valid(vector <int> & nums, int k, int mid){
        int sum=0;
        int arr_used=1;
        for(int num:nums){
            if(num+sum>mid) {
                sum=num;
                arr_used++;
            }
            else sum+=num;
        }
        return arr_used<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        while(low<high){
            int mid= low +(high-low)/2;
            if( valid(nums,k,mid)) high= mid;
            else low= mid+1;
        }
        return low;
    }
};