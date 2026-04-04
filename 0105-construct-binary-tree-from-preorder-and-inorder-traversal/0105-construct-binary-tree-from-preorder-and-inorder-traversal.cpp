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
    TreeNode* call(vector<int>& preorder,int l,int r,int &i,unordered_map<int,int>& mpp){
        if(l>r) return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        int mid=mpp[preorder[i]];
        i++;
        root->left = call(preorder,l,mid-1,i,mpp);
        root->right= call(preorder,mid+1,r,i,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++) mpp[inorder[i]]=i;
        int i=0;
        return call(preorder,0,inorder.size()-1,i,mpp);
    }
};