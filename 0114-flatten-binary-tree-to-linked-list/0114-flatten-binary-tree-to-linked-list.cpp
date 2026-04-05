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
    void call(TreeNode* root,TreeNode* &lastnode){
        if(!root) return;
        TreeNode* left  = root->left;
        TreeNode* right = root->right;
        if(lastnode){
            lastnode->right=root;
            lastnode->left= NULL;
        }
        lastnode=root;
        call(left,lastnode);
        call(right,lastnode);
    }
    void flatten(TreeNode* root) {
        TreeNode* lastnode=NULL;
        call(root,lastnode);
    }
};