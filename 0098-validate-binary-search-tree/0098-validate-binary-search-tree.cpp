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
    // void isValid(TreeNode* root,vector<int> &num) {
    //     if(!root) return;
    //     isValid(root->left,num);
    //     num.push_back(root->val);
    //     isValid(root->right,num);
    // }
    bool isValid(TreeNode* root,long min_val,long max_val) {
        if(!root) return true;
        if(root->val <= min_val || root->val >= max_val) return false;
        return isValid(root->left,min_val,root->val) && isValid(root->right,root->val,max_val);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
        // vector<int> num;
        // isValid(root,num);
        // for(int i=0;i<num.size()-1;i++) {
        //     if(num[i]>=num[i+1]) return false;
        // }
        // return true;
    }
};