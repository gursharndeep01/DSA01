class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int lgh=nums.size();
        vector<int> num(lgh+2);
        num[0]=1;
        num[lgh+1]=1;
        for(int i=1;i<=lgh;i++) num[i]=nums[i-1];
        vector<vector<int>> vec(lgh+2,vector<int>(lgh+2,0));
        for(int frk=2;frk<=lgh+1;frk++){
            for(int i=0;i+frk<=lgh+1;i++){
                int r=i+frk;
                for(int mid=i+1;mid<r;mid++){
                    vec[i][r]=max(vec[i][r],(num[i]*num[r]*num[mid]+ vec[i][mid]+vec[mid][r]));
                }
            }
        }
        return vec[0][lgh+1];
    }
};