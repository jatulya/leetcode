#using backtracking
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[]
        subset = []
        n = len(nums)

        def dfs(i):

            if i >= n:
                res.append(subset.copy())
                return 
            subset.append(nums[i])
            dfs(i+1)
            subset.pop()
            dfs(i+1)
        
        dfs(0)
        return res

  '''not using backtracking
  class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]

        for n in nums:
            if [n] not in res:
                res.append([n])
            
            for l in res:
                if l == [n]:
                    break
                new = l + [n]
                if new not in res:
                    res.append(new)
        
        return res
  '''
