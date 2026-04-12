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
    int call(TreeNode* root,int & fsum){
        if(!root) return 0;
        int lsum=call(root->left,fsum);
        int rsum=call(root->right,fsum);
        lsum = max(0, lsum);
        rsum = max(0, rsum);
        int sum = root->val + lsum + rsum;
        fsum = max(fsum, sum);
        return root->val + max(lsum, rsum);
    }
    int maxPathSum(TreeNode* root) {
        int fsum=INT_MIN;
        call(root,fsum);
        return fsum;
    }
};