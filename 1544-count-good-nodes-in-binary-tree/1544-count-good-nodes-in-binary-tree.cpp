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
    void dfs(TreeNode* node, int maxPar, int& count) {
        if(node->val >= maxPar) {
            count++;
            maxPar = node->val;
        }
        if(node->left) dfs(node->left,maxPar,count);
        if(node->right) dfs(node->right,maxPar,count);
    }
    int goodNodes(TreeNode* root) {
        int count = 1;
        if(root->left) dfs(root->left,root->val,count);
        if(root->right) dfs(root->right,root->val,count);
        return count;
    }
};