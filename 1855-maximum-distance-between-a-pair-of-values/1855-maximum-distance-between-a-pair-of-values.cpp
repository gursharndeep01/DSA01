class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi=0 , n=nums2.size()-1;
        int j=0;
        for(int i=0;i<nums1.size();i++){
            if(j<i) j=i;
            while(j<=n && nums2[j]>=nums1[i]) j++;
            maxi=max(maxi,j-i-1);
        }
        return maxi;
    }
};