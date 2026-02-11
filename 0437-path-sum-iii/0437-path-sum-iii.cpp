/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root,int targetSum,long long sum,unordered_map<long long ,int> &mpp){
        if(!root) return 0;
        int cnt=0;
        sum+=root->val;
        if(sum==targetSum) cnt++;
        if(mpp.count(sum-targetSum)) cnt+=mpp[sum-targetSum];
        mpp[sum]++;
        cnt+=dfs(root->left,targetSum,sum,mpp);
        cnt+=dfs(root->right,targetSum,sum,mpp);
        mpp[sum]--;
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0; 
        unordered_map<long long ,int> mpp;
        return dfs(root,targetSum,0,mpp); 
    }
};