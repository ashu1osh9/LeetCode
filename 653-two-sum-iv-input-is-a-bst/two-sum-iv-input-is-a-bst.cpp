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
 // T.C = > O(N)+O(N)  S.C = O(N + N)
// // class Solution {
// // public:
// //     unordered_map<int,int>map;
// //     vector<int>inorder;
// //     void dfs(TreeNode *root){
// //         if(root == NULL){
// //             return;
// //         }
// //         dfs(root->left);
// //         inorder.push_back(root->val);
// //         map[root->val] = 1;
// //         dfs(root->right);
// //     }

// //     bool findTarget(TreeNode* root, int k) {
// //         inorder.clear();
// //         dfs(root);
// //         int n = inorder.size();
// //         for(int i = 0 ;i<n ;i++){
// //             int data = inorder[i];
// //             int rem = k - data;
// //             map.erase(data);

// //             if(map.find(rem)!= map.end()){
// //                 return true;
// //             }
// //         }

// //         return false;
        
// //     }
// // };

// class BSTIterator {
// public:
//     stack<TreeNode*> st;
//     bool reverse;

//     // reverse = false -> Smallest to Largest
//     // reverse = true  -> Largest to Smallest
//     BSTIterator(TreeNode* root, bool isReverse) {
//         reverse = isReverse;
//         pushAll(root);
//     }

//     // Left iterator  : push left-left-left
//     // Right iterator : push right-right-right
//     void pushAll(TreeNode* node) {
//         while (node != NULL) {
//             st.push(node);

//             if (reverse)
//                 node = node->right;
//             else
//                 node = node->left;
//         }
//     }

//     int next() {
//         TreeNode* temp = st.top();
//         st.pop();

//         // Left Iterator
//         if (!reverse) {
//             pushAll(temp->right);
//         }
//         // Right Iterator
//         else {
//             pushAll(temp->left);
//         }

//         return temp->val;
//     }
// };

// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {

//         BSTIterator left(root, false);   // Smallest iterator
//         BSTIterator right(root, true);   // Largest iterator

//         int i = left.next();
//         int j = right.next();

//         while (i < j) {

//             int sum = i + j;

//             if (sum == k)
//                 return true;

//             else if (sum < k)
//                 i = left.next();

//             else
//                 j = right.next();
//         }

//         return false;
//     }
// };

// T.C = o(n)  , S.C = O(H) 
class Solution {
public:
    stack<TreeNode*> ls;
    stack<TreeNode*> rs;

    void push(TreeNode* root, stack<TreeNode*>& st, bool reverse) {

        while (root) {

            st.push(root);

            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }

    int next(stack<TreeNode*>& st, bool reverse) {

        TreeNode* curr = st.top();
        st.pop();

        if (reverse)
            push(curr->left, st, reverse);
        else
            push(curr->right, st, reverse);

        return curr->val;
    }

    bool findTarget(TreeNode* root, int k) {

        push(root, ls, false);   // Left Iterator
        push(root, rs, true);    // Right Iterator

        int i = next(ls, false);
        int j = next(rs, true);

        while (i < j) {

            if (i + j == k)
                return true;

            else if (i + j > k)
                j = next(rs, true);

            else
                i = next(ls, false);
        }

        return false;
    }
};