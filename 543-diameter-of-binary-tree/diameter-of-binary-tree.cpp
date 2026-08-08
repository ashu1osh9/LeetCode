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

 // dfs - recursion
 // T.c => O(N) -- S.C => O(h)
class Solution {
public:
     int d = 0;
     int solve(TreeNode* root){
        if(root == NULL ){
            return 0;
        }

        int left = solve(root->left);
        int height = solve(root->right);
        d = max(d,left+height);

        return max(left,height) + 1; // kyuki mujhe aage caluculate karne ke liye height chahiye 
     }
    int diameterOfBinaryTree(TreeNode* root) {
         solve(root);
         return d;
        
    }
};