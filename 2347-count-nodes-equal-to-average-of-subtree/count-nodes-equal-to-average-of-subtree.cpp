class Solution {
public:
    int ans = 0;

    int solve(TreeNode* root) {

        if(root == NULL) return 0;

        int value = root->val;

        int left = solve(root->left);
        int right = solve(root->right);

        int sum = value + left + right;

        int tn = count(root);

        int avg = sum / tn;

        if(avg == value)
            ans++;

        return sum;
    }

    int count(TreeNode* root) {

        if(root == NULL)
            return 0;

        int left = count(root->left);
        int right = count(root->right);

        int totalNode = 1 + left + right;


        return totalNode;
    }

    int averageOfSubtree(TreeNode* root) {

        solve(root);

        return ans;
    }
};