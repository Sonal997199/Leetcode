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
    long int num=LONG_MIN;
    bool isValid(TreeNode* root,long maxi,long mini)
    {
        if(!root) return true;
        if(mini<root->val and maxi>root->val)
        {
            return isValid(root->left,root->val,mini) && isValid(root->right,maxi,root->val);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        /*if(!root) return true;
        bool ans=isValidBST(root->left);
        if(root->val>num) num=root->val;
        else return false;

        return ans && isValidBST(root->right);*/

        bool ans=isValid(root,LONG_MAX,LONG_MIN);
        return ans;
        
    }
};