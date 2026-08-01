class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxval;
        deque<int> minval;
        int right=0,left=0;
        int maxsize=0;
        multiset<int> mst;
        while(right<nums.size()){
            while(!maxval.empty() && maxval.back()<nums[right]) maxval.pop_back();
            maxval.push_back(nums[right]);
            while(!minval.empty() && minval.back()>nums[right]) minval.pop_back();
            minval.push_back(nums[right]);
            while((maxval.front()-minval.front())>limit) {
                if(nums[left]==maxval.front()) maxval.pop_front();
                if(nums[left]==minval.front()) minval.pop_front();
                left++;
            }
            maxsize=max(maxsize,right-left+1);
            right++;
        }
        return maxsize;
    }
};