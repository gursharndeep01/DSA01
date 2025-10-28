class Solution {
public:
    void com( vector<vector<int>>&res, vector<int>& ans,vector<int>&candidate,int target,int indx,int sum){
        if(sum>target) return;
        if(sum==target){
            res.push_back(ans);
            return;
        }
        for(int i=indx;i<candidate.size();i++){
            if(i>indx && candidate[i]==candidate[i-1]) continue;
            if(sum>=target) return;
            sum+=candidate[i];
            ans.push_back(candidate[i]);
            com(res,ans,candidate,target,i+1,sum);
            sum-=candidate[i];
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      vector<vector<int>> res;
      vector<int> ans;
      com(res,ans,candidates,target,0,0);
      return res;   
    }
};