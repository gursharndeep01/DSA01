class Solution {
public:
    int  rob1(vector<int> &nums,int start,int size){
        int maxi=0,pre1=0,pre2=0;
        for(int i=start;i<size;i++){
            int crnt=max(pre1,pre2+nums[i]);
            maxi=max(maxi,crnt);
            pre2=pre1;
            pre1=crnt;
        }
        return maxi;
    }
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        else if(size==1) return nums[0];
        else if(size==2) return max(nums[1],nums[0]);
        int max1=rob1(nums,0,size-1);
        int max2=rob1(nums,1,size);
        return max(max1,max2);
    }
};