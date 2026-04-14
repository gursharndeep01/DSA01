class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;
        for (int i = 1; i <= n; i++) xorAll ^= i;
        for (int x : nums) xorAll ^= x;
        int bit = xorAll & (-xorAll);
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (i & bit) a ^= i;
            else b ^= i;
        }
        for (int x : nums) {
            if (x & bit) a ^= x;
            else b ^= x;
        }
        for (int x : nums)
            if (x == a) return {a, b};
        return {b, a};
    }
};