class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int eql=0,left=0;
        for(int x:nums){
            if(target>x)left++;
            else if(target==x) eql++;
        }
        vector<int> vec;
        for(int i=0;i<eql;i++) vec.push_back(left+i);
        return vec;
    }
};