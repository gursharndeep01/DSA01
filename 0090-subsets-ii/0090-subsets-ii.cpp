class Solution {
public:
    void sub(vector<int> &vec,vector<vector<int>> &powset,vector<int> &nums,int i){
        if(i==nums.size()){
            powset.push_back(vec);
            return ;
        }
        vec.push_back(nums[i]);
        sub(vec,powset,nums,i+1);
        int j=i+1;
        while(j<nums.size()&& nums[j]==nums[i]) j++;
        vec.pop_back();
        sub(vec,powset,nums,j);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> powset;
        vector<int> vec;
        sub(vec,powset,nums,0);
        return powset;
    }
};