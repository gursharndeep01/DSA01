class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int mini =INT_MAX, i = 0;
        unordered_map<int, int> mpp;
        for (int& n : nums) {
            int k;
            if (mpp.count(n))
                mini= min(mini, i -mpp[n]);
            for (k = 0; n; n /= 10)
                k = k * 10 + (n % 10);
            mpp[k] = i++;
        }
        return mini==INT_MAX?-1:mini;
    }
};