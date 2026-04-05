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
    TreeNode* call( vector<int>& postorder,unordered_map<int,int> &mpp, int &i,int l,int r){
        if(r<l) return NULL;
        int pos= mpp[postorder[i]];
        TreeNode* root= new TreeNode(postorder[i]);
        i--;
        root->right=call(postorder,mpp,i,pos+1,r);
        root->left=call(postorder,mpp,i,l,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++) mpp[inorder[i]]=i;
        int i=postorder.size()-1;
        return call(postorder,mpp,i,0,inorder.size()-1);
    }
};