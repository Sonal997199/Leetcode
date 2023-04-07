# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def isValid(root,low,high):
            if root is None:
                return True
            if root.val < high and root.val > low:
                a1 = isValid(root.left,low,root.val)
                a2 = isValid(root.right,root.val,high)
                if a1 and a2:
                    return True
                return False
            else:
                return False
        return isValid(root,-inf,inf)