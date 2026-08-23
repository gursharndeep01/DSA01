class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int> stak;
        int k_val=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<k_val) return true;
            while(!stak.empty() && nums[i]>stak.top()){
                k_val= stak.top();
                stak.pop();
            }
            stak.push(nums[i]);
        }
        return false;
    }
};