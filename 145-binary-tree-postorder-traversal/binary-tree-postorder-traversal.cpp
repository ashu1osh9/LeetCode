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
    vector<int>ans = {};
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1,st2;
    if(root==NULL){
        return ans;
    }
        st1.push(root);
        while(!st1.empty()){

            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);

            if(curr->left){
                st1.push(curr->left);
            }
            if(curr->right){
                st1.push(curr->right);
            }

        }

        while(!st2.empty()){
        TreeNode * res = st2.top();
        st2.pop();
        ans.push_back(res->val);
        }

        return ans;
        
    }
};