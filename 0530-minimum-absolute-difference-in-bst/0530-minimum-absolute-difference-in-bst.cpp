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
    int inorder(TreeNode* root,int& val,int& diff)
    {
        if(root->left!=NULL)inorder(root->left,val,diff);
        if(val>=0)diff=min(diff,root->val-val);
        val=root->val;
        if(root->right!=NULL)inorder(root->right,val,diff);
        return diff;
    }
    int getMinimumDifference(TreeNode* root) {
        int diff=INT_MAX;
        int val=-1;
        return inorder(root,val,diff);
    }
};