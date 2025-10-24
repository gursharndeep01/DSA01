class Solution {
public:
    void sub(vector<int> & nums,vector<int> &vec,vector<vector<int>> &ps,int i){
        if(i==nums.size()){
            ps.push_back(vec);
            return;
        }
        vec.push_back(nums[i]);
        sub(nums,vec,ps,i+1);
        vec.pop_back();
        sub(nums,vec,ps,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> ps;
        sub(nums,vec,ps,0);
        return ps;
    }
};