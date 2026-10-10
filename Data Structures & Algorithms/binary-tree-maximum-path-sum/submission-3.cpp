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
    int maxSum ;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int leftGain = max(0,dfs(root->left));
        int rightGain = max(0,dfs(root->right));
        
        int currSum = root->val + leftGain + rightGain; 

        maxSum = max(maxSum, currSum);

        return root->val + max(leftGain,rightGain);
    }
};
