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
    int ans = 0;   
    struct Info {
        bool isBST;
        int  mini, maxi;
        long long sum;  
    };
    Info dfs(TreeNode* root) {
        if (!root) return {true, INT_MAX, INT_MIN, 0};

        auto [li, lmin, lmax, lsum] = dfs(root->left);
        auto [ri, rmin, rmax, rsum] = dfs(root->right);

        if (li && ri && root->val > lmax && root->val < rmin) {
            int mini = min(lmin, root->val);
            int maxi = max(rmax, root->val);
            long long sum = lsum + rsum + root->val;
            ans = max(ans, (int)sum);
            return {true, mini, maxi, sum};
        }
        return {false, 0, 0, 0};  
    }
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};