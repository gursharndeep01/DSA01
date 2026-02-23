class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> khaba(n,-1);
        vector<int> saja(n,-1);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, height[i]);
            khaba[i] = maxi;
        }
        maxi=0;
         int maxSoFar = 0;
        for (int i = n-1; i >=0; i--) {
            maxi = max(maxi, height[i]);
            saja[i] = maxi;
        }
        int area=0;
        for(int i=0;i<n;i++){
            int k=khaba[i],s=saja[i];
            area+= (min(k,s)-height[i]);
        }
        return area;
    }
};