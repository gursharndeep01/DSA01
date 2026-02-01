class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(int i: nums) tsum+=i;
        if(tsum%2 !=0) return false;
        int sum= tsum/2;
        vector<bool> vec(sum+1,false);
        vec[0]=true;
        for(int a:nums){
            for(int x=sum;x>=a;x--){
                vec[x]=vec[x]||vec[x-a];
            }
        }
        return vec[sum];
    }
};