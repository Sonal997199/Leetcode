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
    bool isCousins(TreeNode* root, int x, int y,bool siblings=false,bool cousin=false)
    {
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        int xlevel,ylevel;
        int xparent,yparent;
        
        while(!q.empty())
        {
            TreeNode* n=q.front().first;
            int l=q.front().second.first;
            int par=q.front().second.second;
            q.pop();
            
            if(n->val==x)
            {
                xlevel=l;
                xparent=par;
            }
            else if(n->val==y)
            {
                ylevel=l;
                yparent=par;
            }
            
            if(n->left)
            {
                q.push({n->left,{l+1,n->val}});
            }
            if(n->right)
            {
                q.push({n->right,{l+1,n->val}});
            }
        }
        
        if(xlevel==ylevel)
        {
            if(xparent!=yparent)return true;
        }
        
        return false;
    }
};