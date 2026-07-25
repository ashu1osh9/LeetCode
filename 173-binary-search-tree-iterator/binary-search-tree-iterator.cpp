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
// class BSTIterator {
// public:
//     BSTIterator(TreeNode* root) {
        
//     }
    
//     int next() {
        
//     }
    
//     bool hasNext() {
        
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

// class BSTIterator {
// public:
//     stack<TreeNode*> st;

//     // Push all left nodes into stack
//     void pushLeft(TreeNode* node) {
//         while (node != NULL) {
//             st.push(node);
//             node = node->left;
//         }
//     }

//     // Constructor
//     BSTIterator(TreeNode* root) {
//         pushLeft(root);
//     }

//     int next() {

//         // Top node is the next smallest element
//         TreeNode* temp = st.top();
//         st.pop();

//         // If right subtree exists,
//         // push all its left nodes
//         if (temp->right) {
//             pushLeft(temp->right);
//         }

//         return temp->val;
//     }

//     bool hasNext() {
//         return !st.empty();
//     }
// };


// using the stack 
// class BSTIterator {
// public:
//     stack<TreeNode*>st;
//     void pushallleft(TreeNode* root){
//         while(root != NULL){
//             st.push(root);
//             root = root ->left;
//         }
//     }

//     BSTIterator(TreeNode* root) {
//         pushallleft(root);
//     }
    
//     int next() {

//         TreeNode * curr = st.top();
//         st.pop();
//         if(curr->right!= NULL){
//             pushallleft(curr->right);
//         }


//         return curr->val;

        
//     }
    
//     bool hasNext() {

//         return !st.empty();
        
//     }
// };

// using the vector 

class BSTIterator {
public:
    vector<int>inorder;
    int idx = 0;
    void dfs(TreeNode* root){
        if(root == NULL){
            return ;
        }
    dfs(root->left);
    inorder.push_back(root->val);
    dfs(root->right);

    }

    BSTIterator(TreeNode* root) {
        dfs(root);

        
    }
    
    int next() {

        int ans = inorder[idx];
        idx++;
        return ans ;
        
    }
    
    bool hasNext() {
        if(idx<inorder.size()){
            return true;
        }
        else {
            return false;
        }
    }
};