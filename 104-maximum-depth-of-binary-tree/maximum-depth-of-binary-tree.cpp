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
 // T.C => O(H)
class Solution {
public:
    int maxDepth(TreeNode* root) {

        queue<TreeNode*> que;
    if(root == NULL){
        return 0;
    }
    int level = 0;
        que.push(root);
        while(!que.empty()){
            int n = que.size();

            
            

            while(n--){
                
            TreeNode * curr = que.front();
            que.pop();

                if(curr->left){
                    que.push(curr->left);
                }
                if(curr->right){
                    que.push(curr->right);
                }


            } 
            level++;

        }
        return level;

    }
};