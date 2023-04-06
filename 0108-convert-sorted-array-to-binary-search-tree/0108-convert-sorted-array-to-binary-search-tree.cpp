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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
        {
            return nullptr;
        }
        int m=nums.size()/2;
        TreeNode *p=new TreeNode(nums[m]);
        auto lTree=vector<int>(nums.begin(),nums.begin()+m);
        auto rTree=vector<int>(nums.begin()+m+1,nums.end());
        if(m!=0)
        {
            p->left=sortedArrayToBST(lTree);
        }
        if(m!=nums.size()-1)
        {
            p->right=sortedArrayToBST(rTree);
        }
        return p;
    }
};