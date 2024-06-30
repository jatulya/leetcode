# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# using dfs recursive
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        else:
            return max(self.maxDepth(root.right), self.maxDepth(root.left))+1

'''
using dfs iterative 
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        eleStack = [[root, 1]]
        res = 0

        while eleStack:
            node, depth = eleStack.pop()

            if node:
                res = max(depth, res)
                eleStack.append([node.left, depth+1])
                eleStack.append([node.right, depth+1])
        
        return res
'''
        
