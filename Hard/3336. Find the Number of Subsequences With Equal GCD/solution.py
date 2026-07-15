class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        N = len(nums)

        dp = [[[-1 for k in range (201)]for j in range (201)]for i in range(N)]
        
        result = self.solve(0, 0, 0, nums, dp)

        return result

    def solve(self, idx: int, left: int, right: int, nums: List[int], dp: List[List[List[int]]]) -> int:
        if idx == len(nums):
            if left != 0 and right != 0 and left == right:
                return 1
            return 0

        if dp[idx][left][right] != -1:
            return dp[idx][left][right]

        MOD = 1000000007
        ret = 0

        ret = ret + self.solve(idx + 1, left, right, nums, dp)
        ret = ret % MOD

        ret = ret + self.solve(idx + 1, gcd(left, nums[idx]), right, nums, dp)
        ret = ret % MOD

        ret = ret + self.solve(idx + 1, left, gcd(right, nums[idx]), nums, dp)
        ret = ret % MOD

        dp[idx][left][right] = ret

        return dp[idx][left][right]