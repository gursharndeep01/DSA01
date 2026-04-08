class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n= queries.size();
        int i=0;
        while(i<n){
            for(int j=queries[i][0];j<=queries[i][1];j+=queries[i][2]){
                nums[j]= ((long long )nums[j] * queries[i][3]) % 1000000007;
            }
            i++;
        }
        int xxor=0;
        for(int &x: nums){
            xxor^=x;
        }
        return xxor;
    }
};