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
    // vector<int> preorder;
    // void dopreorderTraversal(TreeNode* root){
    //     if(root == NULL) return;
    //     preorder.push_back(root->val);
    //     dopreorderTraversal(root->left);
    //     dopreorderTraversal(root->right);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // dopreorderTraversal(root);
        vector<int> preorder;
        if(!root) return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right != NULL) st.push(root->right);
            if(root->left != NULL) st.push(root->left); 
        }
        return preorder;
    }
};