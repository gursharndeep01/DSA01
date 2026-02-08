class Solution {
public:
    vector<int> vec;
    void mergesort(int low,int high,vector<pair<int,int>>& aato){
        if (low>=high) return;
        int mid= low+ ((high-low)>>1);
        mergesort(low,mid,aato);
        mergesort(mid+1,high,aato);
        merge(low,mid,high,aato);
    }
    void merge(int low,int mid,int high,vector<pair<int,int>>& aato){
        vector<pair<int,int>> temp;
        int i=low,j=mid+1,cnt=0;
        while(i<=mid && j<=high){
            if(aato[i].first<=aato[j].first){
                vec[aato[i].second]+=cnt;
                temp.push_back(aato[i++]);
            }
            else{
                cnt++;
                temp.push_back(aato[j++]);
            }
        }
        while(i<=mid){
            vec[aato[i].second]+=cnt;
            temp.push_back(aato[i++]);
        }
        while(j<=high){
            temp.push_back(aato[j++]);
        }
        for(int ii=low;ii<=high;ii++){
            aato[ii]=temp[ii-low];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vec.resize(nums.size(),0);
        vector<pair<int,int>> aato;
        for(int i=0;i<nums.size();i++){
            aato.push_back({nums[i],i});
        }
        mergesort(0,nums.size()-1,aato);
        return vec;
    }
};