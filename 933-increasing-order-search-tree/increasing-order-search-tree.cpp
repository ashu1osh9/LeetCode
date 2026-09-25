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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* dummy = new TreeNode(0);
        TreeNode* prev = dummy;

        while (cur || !st.empty()) {

            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();

            prev->left = nullptr;
            prev->right = cur;
            prev = cur;

            cur = cur->right;
        }

        prev->left = nullptr;
        prev->right = nullptr;

        return dummy->right;
    }
};