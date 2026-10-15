class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        int maxi= *max_element(nums.begin(),nums.end());
        vector<int> vec(maxi+1,-1);
        for(int i=0;i<nums.size();i++){
            int count=1;
            sum+=1;
            vec[nums[i]]=i;
            for(int j=i+1;j<nums.size();j++){
                if(vec[nums[j]]!=i){
                    count++;
                    vec[nums[j]]=i;
                }
                sum+=(count*count);
            }
        }
        return sum;
    }
};