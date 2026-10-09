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
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
    int depth(TreeNode* root){
        if(!root) return 0;

        int l = depth(root->left);
        int r = depth(root->right);

        if(l == -1 || r == -1 || abs(l-r) > 1){
            return -1;
        }
        return 1 + max(l,r);
    }
};
