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
    void dfs(TreeNode* root,int targetSum,long long sum,int& cnt){
        if(!root){
            return;
        }
        int vale=root->val;
        sum+=vale;
        if(sum==targetSum) cnt++;
        dfs(root->left,targetSum,sum,cnt);
        dfs(root->right,targetSum,sum,cnt);
        sum-=vale;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0; 
        queue<TreeNode*> q;
        int count=0;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            dfs(curr,targetSum,0,count);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right); 
        }
        return count; 
    }
};