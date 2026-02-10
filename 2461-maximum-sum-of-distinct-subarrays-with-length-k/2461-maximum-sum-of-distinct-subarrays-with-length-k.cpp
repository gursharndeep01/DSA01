class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long no=0,sum=0;
        queue<int> q;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            q.push(nums[i]);
            if(mpp.count(nums[i])){
                i=mpp[nums[i]];
                mpp.clear();
                while(!q.empty()) q.pop (); 
                sum=0;
                continue;
            }
            mpp[nums[i]]=i;
            if(q.size()>k){
                int ii=q.front();q.pop();
                mpp.erase(ii);
                sum-=ii;
            }
            if(sum>no && q.size()==k) no=sum;
        }
        return no;
    }
};