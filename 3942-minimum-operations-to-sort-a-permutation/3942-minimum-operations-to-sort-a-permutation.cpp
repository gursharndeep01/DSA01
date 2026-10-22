class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int idx=0;
        for(int i=0;i<n;i++){
            if(0==nums[i]){
                idx=i;
                break;
            }
        }
        bool inc=true,dec=true;
        for(int i=0;i<n;i++){
            int xx= nums[(i+1)%n];
            if(xx!= (nums[i]+1)%n) inc=false;
            if(xx!= (nums[i]-1+n)%n) dec=false;
        }
        int ans=INT_MAX;
        if(inc) ans=min(ans,min(idx,n-idx+2));
        if(dec) ans=min(ans,min(idx+2,n-idx));
        return ans==INT_MAX?-1:ans;
    }
};