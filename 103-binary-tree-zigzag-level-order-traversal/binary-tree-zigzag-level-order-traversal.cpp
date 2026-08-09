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

  // bfs - search --
//  // T.C => O(N) , S.C = O(H)
// class Solution {
// public:
//     vector<vector<int>> ans;

//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         if(root==NULL)
//             return ans;

//         queue<TreeNode*>q;
//         q.push(root);

//         int i =1;

//         while(!q.empty()) {

//             vector<int>level;
//             int n = q.size();

//             while(n--) {

//                 TreeNode* curr =q.front();
//                 q.pop();

//                 level.push_back(curr->val);

//                 if(curr->left)
//                     q.push(curr->left);

//                 if(curr->right)
//                     q.push(curr->right);
//             }

//             if(i%2 == 0) {
//                 reverse(level.begin(),level.end());
//             }

//             ans.push_back(level);
//             i++;
//         }

//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>>ans={};
        void solve(TreeNode * root , int level ){
            if(root == NULL){
                return ;
            }
            // empty vector hai isliye kuch push nhi hoga kisi bhi index par isliye khali vector push karo 
            if(ans.size()== level){
                ans.push_back({});
            }

            ans[level].push_back(root->val);

            solve(root->left,level+1);
            solve(root->right,level+1);




        }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root , 0);
        for(int i = 1 ;i<ans.size();i= i+2)
{
        reverse(ans[i].begin(), ans[i].end());
}

return ans;



        
    }
};