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
    TreeNode* call(vector<int>& nums,int l,int r){
        if(r<l) return NULL;
        int i= (l+r)>>1;
        TreeNode* root= new TreeNode(nums[i]);
        root->left=call(nums,l,i-1);
        root->right=call(nums,i+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return call(nums,0,nums.size()-1);
    }
};