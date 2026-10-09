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
    int diameterOfBinaryTree(TreeNode* root) {
        // diameter = left_height + right_height
        if(!root) return 0;
        int dia = height(root->left) + height(root->right) + 2;
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);
        return max({dia,leftDia,rightDia});
    }
    
    int height(TreeNode* root){
        if(!root) return -1;
        return 1 + max(height(root->left) , height(root->right));
    }
};
