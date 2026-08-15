class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> lengthi(n,1);
        vector<int> counti(n,1);
        int maxlen=1;
        for(int i=1;i<n;i++){
            for (int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(lengthi[j]+1>lengthi[i]){
                        lengthi[i]=lengthi[j]+1;
                        counti[i]=counti[j];
                    }
                    else if(lengthi[j]+1==lengthi[i]){
                        counti[i]+=counti[j];
                    }
                }
                maxlen=max(maxlen,lengthi[i]);
            }
        }
        int total=0;
        for(int i=0;i<n;i++) if(lengthi[i]==maxlen) total+=counti[i];
        return total;
    }
};