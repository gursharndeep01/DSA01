class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result =0, cnt =0;
        for(int &i : nums ){
            if(cnt==0) result = i;
            if(i== result) cnt++;
            else cnt--;
        }
        return result ;
    }
};