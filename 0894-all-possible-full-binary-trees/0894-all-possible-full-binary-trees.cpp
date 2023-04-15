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
    TreeNode* clone(TreeNode* root)
    {
        TreeNode* node=new TreeNode(0);
        node->left=(root->left)?clone(root->left):nullptr;
        node->right=(root->right)?clone(root->right):nullptr;
        return node;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if(n==1)res.push_back(new TreeNode(0));
        else if(n%2)
        {
            for(int i=2;i<=n;i++)
            {
                auto left=allPossibleFBT(i-1);
                auto right=allPossibleFBT(n-i);
                
                for(int j=0;j<left.size();j++)
                {
                    for(int k=0;k<right.size();k++)
                    {
                        res.push_back(new TreeNode(0));
                        
                        res.back()->left=(k==right.size()-1)?left[j]:clone(left[j]);
                       res.back()->right=(j==left.size()-1)?right[k]:clone(right[k]);
                    }
                }
            }
        }
        
        return res;
    }
};