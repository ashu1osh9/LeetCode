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
 // recursive dfs 
class Solution {
public:
    long long  curr = LLONG_MIN;
    int ans = 1;

    void dfs(TreeNode* root){
        if(root == NULL || ans == 0 ){
            return ;
        }

        dfs(root->left);
        if(root->val<=curr){
            ans = 0;
            return ;
        }
        curr = root ->val;
        dfs(root->right);
        
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        if(ans == 0){
            return false;
        }
        return true;
        
    }
};