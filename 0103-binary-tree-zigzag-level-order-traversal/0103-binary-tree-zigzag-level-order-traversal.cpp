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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        bool l2r = true;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> row(s);
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                int index = (l2r)?i:s-i-1;
                row[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            l2r = !l2r;
            result.push_back(row);
        } 
        return result;
    }
};