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
 // dfs --  preorder/postorder se kar sakte hai -- 
 // T.C => O(N) , S.C => O(N) -- 
class Solution {
public:

    vector<int>ans1, ans2;

    void preorder(TreeNode* root,vector<int>&ans){
        if(root == NULL){
           ans.push_back(INT_MIN);
            return ;
        }

        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preorder(p,ans1);
        preorder(q,ans2);

        return ans1 == ans2;
        
    }
};