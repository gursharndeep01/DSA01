class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ar,area=0,mini;
        while(left<right){
            mini=min(height[left],height[right]);
            ar= (right-left)*mini;
            if(height[left]==mini) left++;
            else right--;
            area=max(ar,area);
        }
        return area;
    }
};