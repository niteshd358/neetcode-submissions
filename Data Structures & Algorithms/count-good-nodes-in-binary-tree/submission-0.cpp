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
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int max_till = INT_MIN;
        dfs(max_till, root,cnt);
        return cnt;
    }
    void dfs(int max_till, TreeNode* root, int &cnt){
        if(!root) return;
        if(root->val >= max_till){
            cnt++;
            max_till = root->val;
        }
        dfs(max_till,root->left,cnt);
        
        dfs(max_till,root->right,cnt);
    }
};
