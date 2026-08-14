class Solution {
public:
    int maximum(int i,int j,vector<int>& arr){
        int max_=INT_MIN;
        for(int a=i-j;a<=i;a++) max_=max(max_,arr[a]);
        return max_;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<n+1;i++){
            int maxval=0;
            for(int j=1;j<=k;j++){
                if(i-j<0) break;
                maxval=max(maxval,arr[i-j]);
                dp[i]= max(dp[i],dp[i-j]+ maxval*j);
            }
        }
        return dp[n];
    }
};