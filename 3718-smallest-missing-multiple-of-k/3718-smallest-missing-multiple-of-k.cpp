class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(),nums.end());
        int ans=k;
        while(set.count(ans)) ans+=k;
        return ans;
    }
};