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
//  // T.C => O(N) , S.C => O(H) --
// class Solution {
// public:
//     int path = INT_MIN;
//     int solve(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }

//         int left = root->val + max(0,solve(root->left));
//         int right = root->val + max(0,solve(root->right));

//         path = max(path , left + right - root->val);

//         return max(left,right);
//     }
//     int maxPathSum(TreeNode* root) {

//         solve(root);
//         return path;
        
//     }
// };


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
    int maxsum;
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int bothpaths=l+r+root->val;
        int bestpath=max(l,r)+root->val;
        int onlyroot=root->val;
        maxsum=max({maxsum,bothpaths,bestpath,onlyroot});
        return max(bestpath,onlyroot);

    }
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        solve(root);
        return maxsum;
        
    }
};