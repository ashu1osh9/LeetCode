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
    vector<int>ans1,ans2;
    void dfs1(TreeNode* &root,vector<int>&ans){

       if (root == NULL) {
            ans.push_back(-1);
            return;
        }

        ans.push_back(root->val);
        dfs1(root->left,ans);
        dfs1(root->right,ans);

    }
    void dfs2(TreeNode* &root,vector<int>&ans){

         if (root == NULL) {
            ans.push_back(-1);
            return;
        }

        ans.push_back(root->val);
        dfs2(root->right,ans);
        dfs2(root->left,ans);
        
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* temp = root;
        dfs1(temp->left,ans1);
        dfs2(root->right,ans2);
        if(ans1==ans2) return true ;
        return false;
        
    }
};