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

    vector<vector<int>> ans;
    vector<int> path;

    int solve(TreeNode* root, int targetSum) {

        if(root == NULL) return 0;

        targetSum = targetSum - root->val;

        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {

            if(targetSum == 0) {
                ans.push_back(path);
            }

            path.pop_back();
            return 1;
        }

        int left = solve(root->left, targetSum);
        int right = solve(root->right, targetSum);

        path.pop_back();

        return left || right;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        solve(root, targetSum);

        return ans;
    }
};