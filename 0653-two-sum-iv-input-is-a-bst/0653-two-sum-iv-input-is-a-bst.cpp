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
    bool find(TreeNode* root, int target, TreeNode* curr){
        if(!root) return false;
        if(root->val == target && root != curr) return true;
        if(target < root->val) return find(root->left, target, curr);
        else  return find(root->right, target, curr);
    }
    bool solve(TreeNode* root, TreeNode* curr, int k){
        if(!curr) return false;
        int target = k - curr->val;
        if(find(root, target, curr)) return true;
        return solve(root, curr->left, k) || solve(root, curr->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return solve(root, root, k);
    }
};