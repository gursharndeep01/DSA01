class Solution {
public:
    void combination (vector<vector<int>> & ans,vector<int> & nums,int indx){
        if(indx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=indx;i<nums.size();i++){
            swap(nums[i],nums[indx]);
            combination(ans,nums,indx+1);
            swap(nums[i],nums[indx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        combination(ans,nums,0);
        return ans;
    }
};