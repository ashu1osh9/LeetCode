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
 // T.C => O(N) , S.C => O(H) --
class Solution {
public:
    int path = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = root->val + max(0,solve(root->left));
        int right = root->val + max(0,solve(root->right));

        path = max(path , left + right - root->val);

        return max(left,right);
    }
    int maxPathSum(TreeNode* root) {

        solve(root);
        return path;
        
    }
};