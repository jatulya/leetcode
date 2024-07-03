"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        nodemap = {}

        def dfs(node): #node is an object of class Node
            if node in nodemap:
                return nodemap[node]
            
            clone = Node(node.val)
            nodemap[node]=clone
            for nodes in node.neighbors:
                clone.neighbors.append(dfs(nodes))
            return clone
        
        return dfs(node) if node else None

        
