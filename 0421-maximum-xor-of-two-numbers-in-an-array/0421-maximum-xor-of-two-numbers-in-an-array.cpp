class Solution {
public:
    struct trienode{
        trienode* t[2];
        trienode() {t[0]=t[1]=NULL;}
    };
    trienode *root = new trienode();
    void make(int num){
        trienode* node= root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) &1;
            if(!node->t[bit]) node->t[bit]= new trienode();
            node= node->t[bit];
        }
    }
    int solve( int num){
        trienode* node=root;
        int ans=00;
        for(int i=31;i>=0;i--){
            int bit= (num>>i)&1;
            int r=1-bit;
            if(node->t[r]){
                ans |=(1<<i);
                node= node->t[r];
            }
            else node= node->t[bit];
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(int num :nums) make(num);
        int ans=0;
        for(int num:nums) ans= max(ans,solve(num));
        return ans;
    }
};