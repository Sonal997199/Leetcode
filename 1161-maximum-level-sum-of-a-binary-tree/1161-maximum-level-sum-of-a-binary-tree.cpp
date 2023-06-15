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
    int maxLevelSum(TreeNode* root) {
        int lvl=0;
        int ans=-1;
        int mx=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            lvl++;
            int sz=q.size();
            int temp=0;
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                temp+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(temp>mx)
            {
                mx=temp;
                ans=lvl;
            }
        }
        
        return ans;
    }
};