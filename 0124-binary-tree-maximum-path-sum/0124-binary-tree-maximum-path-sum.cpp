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
    int height(TreeNode* root,int& pathSum){
        if(root==NULL) return 0;
        int leftSum = max(0,height(root->left,pathSum));
        int rightSum = max(0,height(root->right,pathSum));
        pathSum = max(pathSum,root->val + leftSum + rightSum);
        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        height(root,pathSum);
        return pathSum;
    }
};