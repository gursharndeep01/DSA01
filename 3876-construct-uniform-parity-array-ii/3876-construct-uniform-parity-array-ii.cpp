class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n= nums1.size();
        int mini_odd= INT_MAX;
        for (int i :nums1){
            if(i%2==1 ) mini_odd= min(mini_odd,i);
        }
        if ( mini_odd ==INT_MAX) return true;
        for (int i:nums1){
            if(i%2==0 && i< mini_odd) return false;
        }
        return true;
    }
};