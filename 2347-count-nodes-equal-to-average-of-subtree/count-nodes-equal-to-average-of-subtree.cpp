class Solution {
public:
    int ans = 0;

    int solve(TreeNode* root, int &count) {

        if(root == NULL) {
            count = 0;
            return 0;
        }

        int value = root->val;

        int lc = 0;
        int rc = 0;

        int left = solve(root->left, lc);
        int right = solve(root->right, rc);

        count = 1 + lc + rc;

        int sum = value + left + right;

        int avg = sum / count;

        if(avg == value)
            ans++;

        return sum;
    }

    int averageOfSubtree(TreeNode* root) {

        int count = 0;

        solve(root, count);

        return ans;
    }
};