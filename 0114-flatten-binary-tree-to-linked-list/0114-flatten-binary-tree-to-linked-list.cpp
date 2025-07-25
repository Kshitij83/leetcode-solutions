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
    // TreeNode *prev = NULL;
    void flatten(TreeNode* root) {
        while(root) {
            if(root->left) {
                TreeNode* prev = root->left;
                while(prev->right) prev = prev->right;
                prev->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
        // if(!root) return;
        // flatten(root->right);
        // flatten(root->left);
        // root->right = prev;
        // root->left = NULL;
        // prev = root;
    }
};