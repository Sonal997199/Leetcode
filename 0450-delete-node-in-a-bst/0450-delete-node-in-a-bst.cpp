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
    TreeNode* minVal(TreeNode* root)
    {
        while(root->left!=NULL)root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        
        if(root->val==key)
        {
            if(root->left==NULL and root->right==NULL)
            {
                delete root;
                root=NULL;
                return NULL;
            }
            if(root->left==NULL and root->right)
            {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(root->left and root->right==NULL)
            {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            if(root->left and root->right)
            {
                int mini=minVal(root->right)->val;
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};