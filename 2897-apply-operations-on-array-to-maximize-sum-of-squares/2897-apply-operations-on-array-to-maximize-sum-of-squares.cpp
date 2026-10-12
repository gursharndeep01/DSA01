class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> fre(31,0);
        for(int i:nums){
            for(int j=0;j<31;j++){
                if(i &(1LL<<j)) fre[j]++;
            }
        }
        long long sum=0;
        const int mod=1e9+7;
        for(int i=0;i<k;i++){
            long long x=0;
            for(int j=30;j>=0;j--){
                if(fre[j]>0){
                    x+=(1LL<<j);
                    fre[j]--;
                }
            }
            sum= (sum+x*x)%mod;
        }
        return sum;
    }
};