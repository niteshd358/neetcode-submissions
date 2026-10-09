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
    TreeNode* par = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->left == q || p->right == q) return p;
        if(q->left == p || q->right == p) return q;
        dfs(root,p,q);
        return par;
    }
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return ;
        if(root->val == p->val)
        if(root->val < p->val && root->val < q->val) {
            par = root;
            dfs(root->right,p,q);
            return;
        }

        if(root->val > p->val && root->val > q->val){
            par = root;
            dfs(root->left,p,q);
            return;
        }

        if(root->val > p->val){
            par = root;
            return;
        }
    }
};
