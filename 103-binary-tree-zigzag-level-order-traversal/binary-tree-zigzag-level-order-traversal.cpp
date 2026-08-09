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
    vector<vector<int>> ans;

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return ans;

        queue<TreeNode*>q;
        q.push(root);

        int i =1;

        while(!q.empty()) {

            vector<int>level;
            int n = q.size();

            while(n--) {

                TreeNode* curr =q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }

            if(i%2 == 0) {
                reverse(level.begin(),level.end());
            }

            ans.push_back(level);
            i++;
        }

        return ans;
    }
};