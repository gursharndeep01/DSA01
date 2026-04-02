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
    void fun(TreeNode* root,int row,int clm,map<int,vector<pair<int,int>>> &mpp){
        if(!root) return;
        mpp[clm].push_back({row,root->val});
        fun(root->left,row+1,clm-1,mpp);
        fun(root->right,row+1,clm+1,mpp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mpp;
        fun(root,0,0,mpp);
        vector<vector<int>> vec;
        for(auto & it:mpp){
            auto vecc=it.second;
            sort(vecc.begin(), vecc.end());
            vector<int>tempu;
            for(auto &i: vecc){
                int ii=i.second;
                tempu.push_back(ii); 
            } 
            vec.push_back(tempu);
        }
        return vec;
    }
};