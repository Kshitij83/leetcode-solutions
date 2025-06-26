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
    map<int,int> inMap;
    int preorderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) {
            inMap[inorder[i]] = i;
        }
        return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int> preorder,int start,int end) {
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[preorderIndex++]);

        int mid = inMap[root->val];
        root->left = build(preorder,start,mid-1);
        root->right = build(preorder,mid+1,end);
        return root;
    }
};