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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        
        vector<int> v;
        int ans=1;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int s=q.size();
            int t=q.front().second;
            int a1=0,b1=0;
            for(int i=0;i<s;i++)
            {
                auto p=q.front();
                TreeNode* n=p.first;
                
                long long int k=p.second-t;
                q.pop();
                if(i==0)a1=k;
                if(i==s-1)b1=k;
                
                if(n->left)q.push({n->left,2*k+1});
                if(n->right)q.push({n->right,2*k+2});
            }
            ans=max(ans,b1-a1+1);
        }
        return ans;
    }
};