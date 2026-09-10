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
    int solve(TreeNode* root, int targetSum) {

        if(root == NULL) return 0;

        targetSum = targetSum - root->val;

        if(root->left == NULL && root->right == NULL) {
            if(targetSum == 0) return 1;
            return 0;
        }

        int left = solve(root->left, targetSum);
        int right = solve(root->right, targetSum);

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        return solve(root, targetSum);
    }
};