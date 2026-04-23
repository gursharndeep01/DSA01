class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(n, 0);
        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int k = idx.size();
            vector<long long> prefix(k);
            prefix[0] = idx[0];
            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + idx[i];
            }
            for (int i = 0; i < k; i++) {
                long long left = (long long)i * idx[i] - (i > 0 ? prefix[i - 1] : 0);
                long long right = (prefix[k - 1] - prefix[i]) - (long long)(k - i - 1) * idx[i];

                ans[idx[i]] = left + right;
            }
        }
        return ans;
    }
};