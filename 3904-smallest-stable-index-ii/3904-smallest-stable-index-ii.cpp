class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> right(n);
        int rmin = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            rmin = min(rmin, nums[i]);
            right[i] = rmin;
        }
        
        int lmax = INT_MIN;
        for (int i = 0; i < n; i++) {
            lmax = max(lmax, nums[i]);
            if (lmax - right[i] <= k) return i;
        }
        return -1;
    }
};