class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<tuple<int,int,int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.emplace_back(intervals[i][0], intervals[i][1], intervals[i][2], i);

        sort(arr.begin(), arr.end(),
             [](auto& a, auto& b) { return get<1>(a) < get<1>(b); });

        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> pick(n + 1, vector<vector<int>>(5));

        for (int i = 0; i < n; i++) {
            auto [l, r, w, idx] = arr[i];

            int k = lower_bound(arr.begin(), arr.begin() + i, l,
                    [](auto& t, int val) { return get<1>(t) < val; }) - arr.begin();

            for (int j = 1; j <= 4; j++) {
                long long skip = dp[i][j];
                long long take = dp[k][j - 1] + w;

                if (skip > take) {
                    dp[i + 1][j] = skip;
                    pick[i + 1][j] = pick[i][j];
                } else {
                    vector<int> chosen = pick[k][j - 1];
                    chosen.push_back(idx);
                    sort(chosen.begin(), chosen.end());

                    if (skip == take && pick[i][j] < chosen)
                        chosen = pick[i][j];

                    dp[i + 1][j] = take;
                    pick[i + 1][j] = chosen;
                }
            }
        }
        return pick[n][4];
    }
};