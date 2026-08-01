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


 // T.C => O(N) -- recursive -- inorder 
// class Solution {
// public:
//     TreeNode* ans = NULL;
//     void dfs(TreeNode* root,int val){
//         if(root==NULL){
//             return;
//         }
//         dfs(root->left,val);
//         if(root->val == val){
//             ans = root ;
//             return ;
//         }
//         dfs(root->right,val);
//     }
//     TreeNode* searchBST(TreeNode* root, int val) {
//         dfs(root,val);
//         return ans;
        
//     }
// };

// // dfs iterative 
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {

//         stack<TreeNode*> st;

//         while (root != NULL || !st.empty()) {

//             while (root != NULL) {
//                 st.push(root);
//                 root = root->left;
//             }

//             TreeNode* curr = st.top();
//             st.pop();

//             if (curr->val == val)
//                 return curr;

//             root = curr->right;
//         }

//         return NULL;
//     }
// };
// bst property --=> 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while (root != NULL) {

            if (root->val == val)
                return root;

            else if (val < root->val)
                root = root->left;

            else
                root = root->right;
        }

        return NULL;
    }
};