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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* last;
    TreeNode* middle;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(root->val<prev->val) {
            if(first==NULL) {
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        //optimal approach : TC - O(N) , SC - O(1)
        //idea: while doing inorder traversal keep comparing with its previous value,
        //if there is only one violation then swap those values and in case of second violation swap first with last
        first=last=middle=NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(last) swap(first->val,last->val);
        else swap(first->val,middle->val);


        //easiest approach: find inorder, sort it, traverse both inorder & sorted inorder & see the difference & change those values
        //TC - O(N) + O(NLOGN) + O(N) , SC - O(N)
    }
};