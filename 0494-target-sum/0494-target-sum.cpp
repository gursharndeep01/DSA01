class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int maxsum=0;
        int n=nums.size();
        for(int s :nums) maxsum+=s;
        if(abs(target) > maxsum) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2*maxsum+1,0));
        dp[0][maxsum]=1;
        for(int i=1;i<n+1;i++){
            for(int sum=-maxsum;sum<=maxsum;sum++){
                if(sum-nums[i-1]>=-maxsum && sum-nums[i-1]<=maxsum) 
                dp[i][sum+maxsum]+=dp[i-1][sum - nums[i-1]+maxsum];
                if(sum+nums[i-1]>= -maxsum && sum+nums[i-1]<=maxsum)
                dp[i][sum+maxsum] += dp[i-1][sum+nums[i-1]+maxsum];
            }
        }
        return dp[n][target+ maxsum];
    }
};