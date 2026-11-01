class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        int mine= *min_element(nums.begin(),nums.end());
        int move=0;
        for(int i=0;i<n;i++) move+=(nums[i]-mine);
        return move;
    }
};