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
    int maxPathSum(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* root){
        if(!root) return INT_MIN;
        int sum =0;
        sum += root->val;
        if(root->left) sum += root->left->val;
        if(root->right) sum += root->right->val;

        return max({sum, dfs(root->left), dfs(root->right)});
    }
};
