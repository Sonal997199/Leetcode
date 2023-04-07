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
    void solve(TreeNode* root,vector<vector<int>>&res,vector<int>&v,int sum,int &tg)
    {
        if(!root)return;
        if(!root->left && !root->right)
        {
            if(sum+root->val==tg)
            {
                v.push_back(root->val);
                res.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(root->val);
        solve(root->left,res,v,sum+root->val,tg);
        solve(root->right,res,v,sum+root->val,tg);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        
        solve(root,res,v,0,targetSum);
        return res;
    }
};