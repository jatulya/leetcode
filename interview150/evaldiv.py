class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        adj = collections.defaultdict(list) #for mapping a -> [b, a/b]
        
        #creating the map
        for i, var in enumerate(equations):
            num, denum = var
            adj[num].append([denum, values[i]])
            adj[denum].append([num, 1/values[i]]) #if reversed order is asked
        
        #bfs
        def bfs(src, target):
            if src not in adj or target not in adj:
                return -1
            visited, queue = set(), deque()
            queue.append([src, 1])
            #traversal
            while queue:
                n, w = queue.popleft()
                if n==target:
                    return w
                for adjs, weight in adj[n]:
                    if adjs not in visited:
                        queue.append([adjs, w*weight])
                        visited.add(adjs)
            return -1
        
        return [bfs(q[0],q[1]) for q in queries]

        


        
