class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int reached=0,count=0,maxi=0;
        int i;
        for( i=0;i< nums.size();i++){
            reached=max(reached,i+nums[i]);
            if(i==maxi){
                count++;
                maxi=reached;
                if(reached>=nums.size()-1) break;
            }
        }
        return count;
    }
};