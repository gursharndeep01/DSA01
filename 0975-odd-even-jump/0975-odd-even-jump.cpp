class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n= arr.size();
        vector<vector<bool>> dp(n,vector<bool> (2,false));
        int count=1;
        dp[n-1][0]=true;dp[n-1][1]=true;
        map<int,int> mpp;
        mpp[arr[n-1]]=n-1;
        for(int i=n-2;i>=0;i--){
            
            auto it= mpp.lower_bound(arr[i]);
            if(it!=mpp.end()){
                int j= it->second;
                if(dp[j][1]==true){
                    count++;
                    dp[i][0]=true;
                }
            }
            it = mpp.upper_bound(arr[i]);
            if(it != mpp.begin()) {
                --it;
                int j = it->second;
                if(dp[j][0])
                    dp[i][1] = true;
            }
            mpp[arr[i]]=i;
        } 
        return count;
    }
};