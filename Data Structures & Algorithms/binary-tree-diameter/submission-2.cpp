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
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // diameter = left_height + right_height
        height(root);
        return diameter;
    }
    
    int height(TreeNode* root){
        if(!root) return -1;
        int leftHeight = height(root->left);
        int rightHeight= height(root->right);

        // Diameter passing through this node
        diameter = max(diameter, (leftHeight + rightHeight + 2) );

         // Return height to the parent
        return 1 + max(leftHeight, rightHeight);
    }
};
