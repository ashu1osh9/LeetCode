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
    unordered_map<int,int>map;
    vector<int>inorder;
    void dfs(TreeNode *root){
        if(root == NULL){
            return;
        }
        dfs(root->left);
        inorder.push_back(root->val);
        map[root->val] = 1;
        dfs(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        inorder.clear();
        dfs(root);
        int n = inorder.size();
        for(int i = 0 ;i<n ;i++){
            int data = inorder[i];
            int rem = k - data;
            map.erase(data);

            if(map.find(rem)!= map.end()){
                return true;
            }
        }

        return false;
        
    }
};