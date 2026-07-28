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

    int ans = 0;


    class NodeInfo{
    public:

        bool isBST;
        int sum;
        int mini;
        int maxi;


        NodeInfo(bool b,int s,int mn,int mx){
            isBST = b;
            sum = s;
            mini = mn;
            maxi = mx;
        }
    };


    NodeInfo dfs(TreeNode* root){

        // base case
        if(root == NULL){

            return NodeInfo(
                true,
                0,
                INT_MAX,
                INT_MIN
            );
        }


        // left call
        NodeInfo left = dfs(root->left);


        // right call
        NodeInfo right = dfs(root->right);



        // check BST condition

        if(left.isBST &&
           right.isBST &&
           left.maxi < root->val &&
           right.mini > root->val)
        {

            int sum = left.sum + right.sum + root->val;


            ans = max(ans,sum);



            return NodeInfo(
                true,
                sum,
                min(root->val,left.mini),
                max(root->val,right.maxi)
            );
        }



        // agar BST nahi hai

        return NodeInfo(
            false,
            0,
            0,
            0
        );
    }



    int maxSumBST(TreeNode* root) {

        dfs(root);

        return ans;
    }
};