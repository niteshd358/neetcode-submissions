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
    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MAX, INT_MIN);
    }

    bool validate(TreeNode* root, int maxi, int mini){
        if(!root) return true;

        if(root->val <= mini || root->val >= maxi){
            return false;
        }

        return validate(root->left, root->val, mini) && 
                validate(root->right, maxi, root->val);
    }
};
