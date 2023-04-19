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
    int solve(TreeNode* root,int l,bool shouldGoLeft)
    {
        if(!root)return l;
        int left=0;
        int right=0;
        int temp=0;
        
        if(shouldGoLeft && !root->left)
        {
            temp=l;
            l=0;
        }
        else if(!shouldGoLeft && !root->right)
        {
            temp=l;
            l=0;
        }
        
        right=solve(root->right,shouldGoLeft?1:l+1,true);
        left=solve(root->left,shouldGoLeft?l+1:1,false);
        
        return max({left,right,l,temp});
    }
    int longestZigZag(TreeNode* root) {
        if(!root->left && !root->right)return 0;
        
        return solve(root,0,false);
    }
};