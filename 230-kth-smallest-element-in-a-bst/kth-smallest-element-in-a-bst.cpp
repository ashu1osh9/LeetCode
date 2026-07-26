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



//  // T.c => O(v) S.C => O(V) 
// class Solution {
// public:
// vector<int>inorder;

//     void dfs(TreeNode* root ){
//         if(root == NULL){
//             return ;
//         }
//         dfs(root->left);
//         inorder.push_back(root->val);
//         dfs(root->right);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         inorder.clear();
//         dfs(root);

//         return inorder[k-1];
//     }
// };
class Solution {
public:

    int count = 0;
    int ans = 0;

    void dfs(TreeNode* root, int k){

        if(root == NULL)
            return;

        dfs(root->left, k);

        count++;

        if(count == k){
            ans = root->val;
            return;
        }

        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        dfs(root, k);

        return ans;
    }
};