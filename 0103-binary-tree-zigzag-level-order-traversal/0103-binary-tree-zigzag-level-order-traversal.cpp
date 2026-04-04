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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if (!root) return vec;
        queue<TreeNode*> q;
        q.push(root);
        int cnt=1;
        while(!q.empty()){
            vector<int> vecc;
            int i=cnt;
            cnt=0;
            for(int j=0;j<i;j++){
                TreeNode* tempu= q.front();q.pop();
                vecc.push_back(tempu->val);
                if(tempu->left){
                    q.push(tempu->left);
                    cnt++;
                }
                if(tempu->right){
                    q.push(tempu->right);
                    cnt++;
                }
            }
            vec.push_back(vecc);
        }
        for(int i=0;i<vec.size();i++){
            if(i%2==0)continue;
            reverse(vec[i].begin(),vec[i].end());
        }
        return vec;
    }
};