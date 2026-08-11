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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {

        // base case
        if (root == NULL)
            return NULL;

        if (root == p || root == q)
            return root;

        TreeNode* left = solve(root->left, p, q);
        TreeNode* right = solve(root->right, p, q);

        // p and q different sides mein hain
        if (left != NULL && right != NULL)
            return root;

        // sirf left side mein mila
        if (left != NULL)
            return left;

        // sirf right side mein mila
        return right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return solve(root, p, q);
    }
};