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

//   // recursive dfs  == T.C => O(N) , S.C => 0(N)
// class Solution {
// public:
//     long long  curr = LLONG_MIN;
//     int ans = 1;

//     void dfs(TreeNode* root){
//         if(root == NULL || ans == 0 ){
//             return ;
//         }

//         dfs(root->left);
//         if(root->val<=curr){
//             ans = 0;
//             return ;
//         }
//         curr = root ->val;
//         dfs(root->right);
        
//     }
//     bool isValidBST(TreeNode* root) {
//         dfs(root);
//         if(ans == 0){
//             return false;
//         }
//         return true;
        
//     }
// };
// stack 
class Solution {
public:
 long long ans = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){


            while(curr){
                st.push(curr);
                curr = curr->left;
            }

            TreeNode * data = st.top();
            st.pop();
            if(data->val<=ans){
                
                return false;
            }
            ans = data->val;

            curr = data ->right;


        }
        return true;
        
    }
};