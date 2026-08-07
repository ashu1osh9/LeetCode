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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans = {};
        if(root == NULL){
            return ans;

        }
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>level;

            while(n--)

           { 
            
            TreeNode * curr = q.front();
            level.push_back(curr->val);
            q.pop();

            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
            
            
            
            
            }

            ans.push_back(level);







        }
        return ans;
        
    }
};