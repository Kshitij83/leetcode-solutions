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
    unordered_map<TreeNode*,int> dp; 
    int rob(TreeNode* root) {

        //idea : think of the problem as a take|not take problem
        //suppose u took node then find the max at that point by calculating maxes from two levels below
        //if u decide not to take node, calculate maxes at that point by one level below

        if(!root) return 0;
        if(dp.count(root)) return dp[root];
        int take = root->val + 
        (root->left == NULL ? 0 : rob(root->left->left) + rob(root->left->right)) + 
        (root->right == NULL ? 0 : rob(root->right->left) + rob(root->right->right));
        int nottake = (root->left == NULL ? 0 : rob(root->left)) + (root->right == NULL ? 0 : rob(root->right));
        dp[root] = max(take,nottake);
        return dp[root];
    }
};