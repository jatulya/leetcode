class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum, currSum = -inf, 0

        for n in nums:
            currSum = max(n, currSum + n)
            maxSum = max(maxSum, currSum)
        
        return maxSum


'''using Kadane's algorithm '''
