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
    int maxSum = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int l = solve(root->left);
        int r = solve(root->right);
        
        int neeche_hi_mil_gaya = l + r + root->val;
        int koi_ek_acche_hai = max(l,r) + root->val;
        int ek_root_accha_hai = root->val;
        maxSum = max({maxSum,neeche_hi_mil_gaya,koi_ek_acche_hai,ek_root_accha_hai});

        return max(koi_ek_acche_hai,ek_root_accha_hai);

    }


    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
        
    }
};