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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if (root == NULL)
            return result;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {

            int n = que.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {

                TreeNode* curr = que.front();
                que.pop();

                level.push_back(curr->val);

                if (curr->left)
                    que.push(curr->left);

                if (curr->right)
                    que.push(curr->right);
            }

            result.push_back(level);
        }

        return result;
    }
};