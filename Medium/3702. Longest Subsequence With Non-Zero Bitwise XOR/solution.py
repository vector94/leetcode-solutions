class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        Xor = 0
        nonZero = False
        for n in nums:
            Xor ^= n
            if n != 0:
                nonZero = True

        if not nonZero:
            return 0
        if Xor == 0:
            return len(nums) - 1
        return len(nums)
        