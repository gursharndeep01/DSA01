class Solution {
public:
    void per(vector<vector<int>>& res,vector<int> nums,int indx){
        if(indx==nums.size()){
            res.push_back(nums);return;
        }
        unordered_set<int> set;
        for(int i=indx;i<nums.size();i++){
            if(set.count(nums[i])) continue;
            set.insert(nums[i]);
            swap(nums[i],nums[indx]);
            per(res,nums,indx+1);
            swap(nums[indx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        per(res,nums,0);
        return res;
    }
};