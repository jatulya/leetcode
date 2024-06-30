
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.d = 0
        self.dfsRec(root)
        return self.d

    def dfsRec(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0
        
        lDepth = self.dfsRec(node.left)
        rDepth = self.dfsRec(node.right)
        
        self.d = max(self.d, lDepth+rDepth)

        return max(lDepth, rDepth)+1

    
    
        
