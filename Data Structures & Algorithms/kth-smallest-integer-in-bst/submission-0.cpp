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
    int cnt = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inorder(root,k,result);
        return result;
    }

    void inorder(TreeNode* root, int k, int &result){
        if(root->left) inorder(root->left,k,result);
        cnt++;
        if(cnt == k) {
            result = root->val;
            return;
        }
        if(root->right) inorder(root->right,k,result);
    }
};
