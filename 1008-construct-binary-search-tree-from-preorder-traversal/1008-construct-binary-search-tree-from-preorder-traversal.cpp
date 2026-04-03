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
    TreeNode* tra(vector<int> &preorder,int maxv,int minv,int &i ){
        if(i>=preorder.size()) return NULL;
        if(preorder[i]>maxv || preorder[i]<minv) return NULL;
        TreeNode* root= new TreeNode(preorder[i]);
        int val= preorder[i];
        i++;
        root->left= tra(preorder,val,minv,i);
        root->right= tra(preorder,maxv,val,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return tra(preorder,INT_MAX,INT_MIN,i);
    }
};