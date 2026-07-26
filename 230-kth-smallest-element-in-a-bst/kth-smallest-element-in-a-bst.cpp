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


// recursive dfs 
// // T.C => 0(N) , S.C => 0(n);
// class Solution {
// public:

//     int count = 0;
//     int ans = 0;

//     void dfs(TreeNode* root, int k){

//         if(root == NULL)
//             return;

//         dfs(root->left, k);

//         count++;

//         if(count == k){
//             ans = root->val;
//             return;
//         }

//         dfs(root->right, k);
//     }

//     int kthSmallest(TreeNode* root, int k) {

//         dfs(root, k);

//         return ans;
//     }
// };

// using the stack 

class Solution {
public:



    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*>st;
        TreeNode* curr = root;

        while(curr != NULL || !st.empty()){

            while(curr){
                st.push(curr);
                curr = curr ->left;
            }

            TreeNode* value = st.top();
            st.pop();

            k--;
            if(k==0){
                return value->val;
            }       

            curr = value->right;
        
        }
        

        return -1;
    }
};