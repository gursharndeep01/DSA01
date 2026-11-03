class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves=0,maxe=*max_element(nums.begin(),nums.end());
        for(int i:nums) moves+=(maxe-i);
        return moves;
    }
};