class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n= nums.size()-2;
        vector<int> ans={};
        vector<int> fre(n,0);
        for(int i=0;i<n+2;i++){
            fre[nums[i]]++;
            if(fre[nums[i]]==2) ans.push_back(nums[i]);
        }
        return ans;
    }
};