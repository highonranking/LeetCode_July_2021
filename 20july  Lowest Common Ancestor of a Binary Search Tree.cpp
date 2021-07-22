/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (root == NULL) return NULL;
 
    // If both n1 and n2 are smaller
    // than root, then LCA lies in left
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
 
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
 
    return root;
    }
};
