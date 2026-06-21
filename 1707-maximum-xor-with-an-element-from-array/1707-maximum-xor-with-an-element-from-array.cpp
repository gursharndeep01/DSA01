class Solution {
public:
    struct trienode{
        trienode *t[2];
        trienode(){t[1]=t[0]=NULL;}
    };
    trienode* root= new trienode();
    void make(int num){
        trienode* node= root;
        for(int i=31;i>=0;i--){
            int bit= (num>>i) &1;
            if(!node->t[bit]) node->t[bit]= new trienode();
            node=node->t[bit];
        }
    }
    int solve(int num){
        trienode* node= root;
        int ans =0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int r= 1-bit;
            if(node->t[r]){
                ans |=(1<<i);
                node=node->t[r];
            }
            else node=node->t[bit];
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> vec;
        for(int i=0;i<queries.size();i++) vec.push_back({queries[i][1],queries[i][0],i});
        sort(vec.begin(),vec.end());
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans(queries.size(),-1);
        int ii=0;bool empty=true;
        for(auto &it: vec){
            int m=it[0],x=it[1],i=it[2];
            while(ii<n && nums[ii]<=m){
                make(nums[ii++]);
                empty=false;
            }
            if(!empty){
                ans[i]=solve(x);
            } 
        }
        return ans;
    }
};