class Solution {
public:
    void com(vector<vector<int>> &res,vector<int> &ans,vector<int>&candidates,int target,int indx,int sum){
        if(sum>target) return;
        if(sum==target){
            res.push_back(ans);
            return;
        }
        for(int i=indx;i<candidates.size();i++){
            sum+=candidates[i];
            ans.push_back(candidates[i]);
            com(res,ans,candidates,target,i,sum);
            sum-=candidates[i];
            ans.pop_back();
            if(sum>=target) return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        com(res,ans,candidates,target,0,0);
        return res;
    }
};