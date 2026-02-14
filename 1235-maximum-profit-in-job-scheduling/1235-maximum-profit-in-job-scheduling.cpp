class Solution {
public:
    int solve(int i, vector<vector<int>>& jobs, vector<int>& vec, vector<int>& dp) {
        if(i >= jobs.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int nextIndex = lower_bound(vec.begin(),vec.end(),jobs[i][1]) -vec.begin();
        int take = jobs[i][2] + solve(nextIndex,jobs, vec, dp);
        int ntake = solve(i+1, jobs,vec, dp);
        return dp[i] = max(take, ntake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        vector<int> vec;
        for(auto &x : jobs)
            vec.push_back(x[0]);
        vector<int> dp(n, -1);
        return solve(0,jobs,vec,dp);
    }
};
