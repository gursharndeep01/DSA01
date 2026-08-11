class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        vector<int> next_ele(n,-1);
        stack<int> stak;
        for(int i=2*n-1;i>=0;i--){
            while(!stak.empty() && stak.top()<=nums[i%n]) stak.pop();
            if(!stak.empty())next_ele[i%n] = stak.top();
            stak.push(nums[i%n]);
        }
        return next_ele;
    }
};